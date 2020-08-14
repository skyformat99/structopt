#include <structopt/app.hpp>

struct StyleOptions {
  enum class Color {red, green, blue};

  // e.g., `--color red`
  std::optional<Color> color = Color::red;
};
STRUCTOPT(StyleOptions, color);



int main(int argc, char *argv[]) {

  auto app = structopt::app("my_app");

  try {

    auto options = app.parse<StyleOptions>(argc, argv);

    if (options.color == StyleOptions::Color::red) {
        std::cout << "#ff0000\n";
    }
    else if (options.color == StyleOptions::Color::blue) {
        std::cout << "#0000ff\n";
    }
    else if (options.color == StyleOptions::Color::green) {
        std::cout << "#00ff00\n";
    }

  } catch (std::exception& e) {
    std::cout << e.what() << "\n";
    app.print_help();
  }
}
