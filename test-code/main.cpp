#include <expected>
#include <print>
#include <random>

auto genRandom() -> std::expected<int, float> {
  std::random_device rd;
  std::default_random_engine engine(rd());
  std::uniform_int_distribution dist(-10, 10);

  if (const auto val = dist(engine);  val > 0) {
    return val;
  } else {
    return std::unexpected(static_cast<float>(val));
  }  
}

int main() {
  const auto _ = genRandom().and_then([](auto&& val) -> std::expected<int, float> {
    std::print("Nice! {}", val);
    return val;
  }).or_else([](auto&& val) -> std::expected<int, float> {
    std::print("Not nice! {}", val);
    return std::unexpected(val);
  });
}