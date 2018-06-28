#include <iostream>

uint32_t next_divisible(const uint32_t n, const uint32_t divisor) {
  uint32_t distant = divisor - (n%divisor);
  if (distant == divisor) {
    distant = 0;
  }
  return n + distant;
}

void no_modulo(const uint32_t begin, const uint32_t end) {
  uint32_t next_fizz = next_divisible(begin, 3);
  uint32_t next_buzz = next_divisible(begin, 5);

  for (uint32_t i = begin; i <= end; ++i) {
    bool is_fizz_or_buzz = false;
    if (i == next_fizz) {
      next_fizz += 3;
      std::cout << "Fizz";
      is_fizz_or_buzz = true;
    }

    if (i == next_buzz) {
      next_buzz += 5;
      std::cout << "Buzz";
      is_fizz_or_buzz = true;
    }

    if (!is_fizz_or_buzz) {
      std::cout << i;
    }

    std::cout << "\n";
  }

  std::cout.flush();
}

void append(const uint32_t begin, const uint32_t end) {
  for (uint32_t i = begin; i <= end; ++i) {
    const bool fizz = (i%3==0);
    const bool buzz = (i%5==0);
    if (fizz) {
      std::cout << "Fizz";
    }
    if (buzz) {
      std::cout << "Buzz";
    }
    if (!(fizz || buzz)) {
      std::cout << i;
    }
    std::cout << '\n';
  }

  std::cout.flush();
}

void store_common_result(const uint32_t begin, const uint32_t end) {
  for (uint32_t i = begin; i <= end; ++i) {
    const bool fizz = (i%3==0);
    const bool buzz = (i%5==0);
    if (fizz && buzz) {
      std::cout << "FizzBuzz";
    } else if (fizz) {
      std::cout << "Fizz";
    } else if (buzz) {
      std::cout << "Buzz";
    } else {
      std::cout << i;
    }
    std::cout << '\n';
  }

  std::cout.flush();
}

void naive(const uint32_t begin, const uint32_t end) {
  for (uint32_t i = begin; i <= end; ++i) {
    if (i % 3 == 0 && i % 5 == 0) {
      std::cout << "FizzBuzz";
    } else if (i % 3 == 0) {
      std::cout << "Fizz";
    } else if (i % 5 == 0) {
      std::cout << "Buzz";
    } else {
      std::cout << i;
    }
    std::cout << '\n';
  }

  std::cout.flush();
}

int main() {
  uint32_t begin, end;
  std::cin >> begin >> end;
  //naive(begin, end);
  //store_common_result(begin, end);
  append(begin, end);
  //no_modulo(begin, end);
}
