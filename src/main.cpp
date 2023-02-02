
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>

#include <imgui.h> // necessary for ImGui::*, imgui-SFML.h doesn't include imgui.h
#include <imgui-SFML.h> // for ImGui::SFML::* functions and SFML-specific overloads

#include <variant>
#include <docopt.h>
#include <spdlog/spdlog.h>

static const char USAGE[] =
R"(Naval Fate.
  Usage:
          imgui-sfml-starter [options]

  Options:
          -h --help           Show this screen.
          --width=WIDTH       Screen width in pixels [default: 1024].
          --height=HEIGHT     Screen height in pixels [default: 768].
          --scale=SCALE       Scaling factor [default: 2].

)";

int main(int argc, const char** argv) {

  std::map<std::string, docopt::value> args = docopt::docopt(USAGE,
                                                     { std::next(argv), std::next(argv, argc) },
                                                       true,// show help if requested
                                                      "imgui-sfml-starter 0.0");// version string

  const auto width  = args["--width"].asLong();
  const auto height = args["--height"].asLong();
  const auto scale  = args["--scale"].asLong();

  if (width < 0 || height < 0 || scale < 1 || scale > 5) {
    spdlog::error("Command line options are out of reasonable range.");
    for (auto const &arg : args) {
      if (arg.second.isString()) { spdlog::info("Parameter set: {}='{}'", arg.first, arg.second.asString())
                ; }
    }
    abort();
  }

  spdlog::set_level(spdlog::level::debug);
  // Use the default logger (stdout, multi-threaded, colored)
  spdlog::info("Hello, {}!", "World");

  sf::ContextSettings settings;
  settings.antialiasingLevel = 4;
  auto vm = sf::VideoMode(static_cast<unsigned int>(width), static_cast<unsigned int>(height), 32);
  sf::RenderWindow window(vm, "ImGui + SFML = <3",  sf::Style::Titlebar | sf::Style::Close, settings);
  window.setFramerateLimit(60);
  if (!ImGui::SFML::Init(window, true) ) {
    return -1;
  }

  const auto scale_factor = static_cast<float>(scale);
  ImGui::GetStyle().ScaleAllSizes(scale_factor);
  ImGui::GetIO().FontGlobalScale = scale_factor;

  settings = window.getSettings();
  fmt::print( "SFML: {}.{}.{}\n", SFML_VERSION_MAJOR, SFML_VERSION_MINOR, SFML_VERSION_PATCH);
  fmt::print( "OPEN GL: {}.{}\n", settings.majorVersion, settings.minorVersion);

  sf::CircleShape shape(100.f);
  shape.setFillColor(sf::Color::Green);

  sf::Clock deltaClock;
  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      ImGui::SFML::ProcessEvent(window, event);

      if (event.type == sf::Event::Closed) {
        window.close();
      }
    }

    ImGui::SFML::Update(window, deltaClock.restart());

    ImGui::ShowDemoWindow();

    ImGui::Begin("Hello, world!");
    ImGui::Button("Look at this pretty button");
    ImGui::End();

    window.clear();
    window.draw(shape);
    ImGui::SFML::Render(window);
    window.display();
  }

  ImGui::SFML::Shutdown();

  return 0;
}
