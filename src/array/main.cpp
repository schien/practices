#include <iostream>
#include "input_helper.h"

#include "solution.cpp"

void usage() {
  std::cout << "[usage] i {n x_1 ... x_n} {m y_1 ... y_m}\n"
            << "        t {n x_1 ... x_n} k\n"
            << "        m {n x_1 ... x_n}\n"
            << "        p {n x_1 ... x_n}\n"
            << "        d {n x_1 ... x_n}\n"
            << "        s {n x_1 ... x_n}\n"
            << "        k {n x_1 ... x_n} k\n"
            << "        3 {n x_1 ... x_n}\n"
            << "        l {n x_1 ... x_n}\n"
            << "        c {n [0|1|2]*}\n"
            << "        e {n x_1 ... x_n}\n"
            << "        j {n x_1 ... x_n}\n"
            << "        g {n x_1 ... x_n}\n"
            << "        x {n x_1 ... x_n}\n"
            << "        r {n x_1 ... x_n} t\n"
            << "        b {n x_1 ... x_n} t\n"
            << "        w {n x_1 ... x_n} t\n"
            << "        1 {n [0|1]*}\n"
            << "        a {n x_1 ... x_n} t\n"
            << "        P {n x_1 ... x_n} t\n"
            << "        I {n x_1 ... x_n} t\n"
            << "        T {n x_1 ... x_n} t\n"
            << "        M {n x_1 ... x_n} k\n"
            << "        S {n x_1 ... x_n}\n"
            << "        A {n x_1 ... x_n}\n"
            << "        f {n x_1 ... x_n} k\n"
            << "        F {n x_1 ... x_n}\n"
            << "        C {n x_1 ... x_n} k\n"
            << "        R {n x_1 ... x_n} i j\n"
            << "        K {n x_1 ... x_n} k v_1 ...\n"
            << "        D {n x_1 ... x_n} k\n"
            << "        G {n x_1 ... x_n}\n"
            << "        u {n x_1 ... x_n} k\n"
            << "        0 {n x_1 ... x_n} k\n"
            << "        o {n x_1 ... x_n}\n"
            << "        n {n x_1 ... x_n}\n"
            << "        2 {n x_1 ... x_n}\n"
            << "        = {n x_1 ... x_n}\n"
            << std::flush;
}

void output_vector(vector<int>& vec) {
  for (auto n : vec) {
    std::cout << n << ' ';
  }
  std::cout << std::endl;
}

void runIntersect() {
  std::vector<int> num1 = next_vector<int>();
  std::vector<int> num2 = next_vector<int>();

  Solution solution;
  auto output = solution.intersection(num1, num2);
  output_vector(output);

  output = solution.intersect(num1, num2);
  output_vector(output);
}

void runTopKFrequent() {
  std::vector<int> num = next_vector<int>();
  int k = next<int>();

  Solution solution;
  auto output = solution.topKFrequent(num, k);
  output_vector(output);
}

void runProductExceptSelf() {
  std::vector<int> num = next_vector<int>();

  Solution solution;
  auto output = solution.productExceptSelf(num);
  output_vector(output);
}

void runPermutation() {
  std::vector<int> num = next_vector<int>();

  Solution solution;
  auto output = solution.permute(num);
  for (auto vec : output) {
    output_vector(vec);
  }
}

void runFindDuplicate() {
  std::vector<int> num = next_vector<int>();
  Solution solution;
  std::cout << solution.findDuplicate(num) << std::endl;
}

void runSubset() {
  std::vector<int> num = next_vector<int>();
  Solution solution;
  auto output = solution.subsets(num);
  for (auto vec : output) {
    output_vector(vec);
  }
}

void runKthLargest() {
  std::vector<int> num = next_vector<int>();
  int k = next<int>();
  Solution solution;
  auto output = solution.findKthLargest(num, k);
  std::cout << output << std::endl;
}

void runIncreasingTriplet() {
  std::vector<int> num = next_vector<int>();
  Solution solution;
  auto output = solution.increasingTriplet(num);
  std::cout << std::boolalpha << output << std::endl;
}

void runLIS() {
  std::vector<int> num = next_vector<int>();
  Solution solution;
  auto output = solution.lengthOfLIS(num);
  std::cout << output << std::endl;
}

void runSortColors() {
  std::vector<int> input = next_vector<int>();
  Solution solution;
  solution.sortColors(input);
  output_vector(input);
}

void runFindPeakElement() {
  std::vector<int> num = next_vector<int>();
  Solution solution;
  auto output = solution.findPeakElement(num);
  std::cout << output << std::endl;
}

void runJumpGame() {
  std::vector<int> num = next_vector<int>();
  Solution solution;
  auto output = solution.canJump(num);
  std::cout << output << std::endl;
}

void runLargestNumber() {
  std::vector<int> num = next_vector<int>();
  Solution solution;
  auto output = solution.largestNumber(num);
  std::cout << output << std::endl;
}

void runMaxProduct() {
  std::vector<int> num = next_vector<int>();
  Solution solution;
  auto output = solution.maxProduct(num);
  std::cout << output << std::endl;
}

void runSearchRotate() {
  std::vector<int> num = next_vector<int>();
  int target = next<int>();
  Solution solution;
  auto output = solution.search(num, target);
  std::cout << output << std::endl;
}

void runSearchRange() {
  std::vector<int> num = next_vector<int>();
  int target = next<int>();
  Solution solution;
  auto output = solution.searchRange(num, target);
  for (auto n:output) {
    std::cout << n << ' ';
  }
  std::cout << std::endl;
}

void runWiggleSort() {
  std::vector<int> num = next_vector<int>();
  Solution solution;
  solution.wiggleSort(num);
  output_vector(num);
}

void runMaxConsecutiveOnes() {
  std::vector<int> num = next_vector<int>();
  Solution solution;
  std::cout << solution.findMaxConsecutiveOnes(num) << std::endl;
}

void runMinCostClimbStair() {
  std::vector<int> num = next_vector<int>();
  Solution solution;
  std::cout << solution.findMaxConsecutiveOnes(num) << std::endl;
}

void runPeakIndex() {
  std::vector<int> num = next_vector<int>();
  Solution solution;
  std::cout << solution.peakIndexInMountainArray(num) << std::endl;
}

void runCheckNonDecreasing() {
  std::vector<int> num = next_vector<int>();
  Solution solution;
  std::cout << std::boolalpha << solution.checkPossibility(num) << std::endl;
}

void runThirdMax() {
  std::vector<int> num = next_vector<int>();
  Solution solution;
  std::cout << solution.thirdMax(num) << std::endl;
}

void runMaxSlidingWindow() {
std:vector<int> num = next_vector<int>();
    int k = next<int>();
    Solution solution;
    auto output = solution.maxSlidingWindow(num, k);
    for (auto n : output) {
      std::cout << n << ' ';
    }
    std::cout << std::endl;
}

void runMinPairSum() {
  std::vector<int> nums = next_vector<int>();
  Solution solution;
  auto output  = solution.arrayPairSum(nums);
  std::cout << output << std::endl;
}

void runSortArrayByParity() {
  std::vector<int> nums = next_vector<int>();
  Solution solution;
  auto output = solution.sortArrayByParity(nums);
  for (auto n : output) {
    std::cout << n << ' ';
  }
  std::cout << std::endl;
}

void runCanPlaceFlowers() {
  std::vector<int> nums = next_vector<int>();
  Solution solution;
  auto output = solution.canPlaceFlowers(nums, next<int>());
  std::cout << std::boolalpha << output << std::endl;
}

void runFindUnsortedSubarray() {
  std::vector<int> nums = next_vector<int>();
  Solution solution;
  auto output = solution.findUnsortedSubarray(nums);
  std::cout << output << std::endl;
}

void runCheckSubarraySum() {
  std::vector<int> nums = next_vector<int>();
  Solution solution;
  auto output = solution.checkSubarraySum(nums, next<int>());
  std::cout << std::boolalpha << output << std::endl;
}

void runSumRange() {
  NumArray nums(next_vector<int>());
  auto output = nums.sumRange(next<int>(), next<int>());
  std::cout << output << std::endl;
}

void runKthLargestInStream() {
  std::vector<int> nums = next_vector<int>();
  int k = next<int>();
  KthLargest kth(k, nums);

  while (true) {
    int val;
    std::cin >> val;
    if (std::cin.eof()) {
      break;
    }
    auto output = kth.add(val);
    std::cout << output << std::endl;
  }
}

void runSmallestRangeI() {
  std::vector<int> nums = next_vector<int>();
  Solution solution;
  auto output = solution.smallestRangeI(nums, next<int>());
  std::cout << output << std::endl;
}

void runGroupSizeX() {
  std::vector<int> nums = next_vector<int>();
  Solution solution;
  auto output = solution.hasGroupsSizeX(nums);
  std::cout << std::boolalpha << output << std::endl;
}

void runKdiffPair() {
  std::vector<int> nums = next_vector<int>();
  Solution solution;
  auto output = solution.findPairs(nums, next<int>());
  std::cout << output << std::endl;
}

void runThreeSum() {
  std::vector<int> nums = next_vector<int>();
  Solution solution;
  auto output = solution.threeSum(nums);
  for (auto& v : output) {
    std::cout << v[0] << ' ' << v[1] << ' ' << v[2] << '\n';
  }
  std::cout << std::flush;
}

void runFirstMissingPositive() {
  std::vector<int> nums = next_vector<int>();
  Solution solution;
  auto output = solution.firstMissingPositive(nums);
  std::cout << output << std::endl;
}

void runIsMonotonic() {
  std::vector<int> nums = next_vector<int>();
  Solution solution;
  auto output = solution.isMonotonic(nums);
  std::cout << std::boolalpha << output << std::endl;
}

void runSortArrayByParityII() {
  std::vector<int> nums = next_vector<int>();
  Solution solution;
  auto output = solution.sortArrayByParityII(nums);
  for (auto n : output) {
    std::cout << n << ' ';
  }
  std::cout << std::endl;
}

void runPivotIndex() {
  std::vector<int> nums = next_vector<int>();
  Solution solution;
  auto output = solution.pivotIndex(nums);
  std::cout << output << std::endl;
}

int main() {
  char op = next<char>();

  switch(op) {
    case 'i':
      runIntersect();
      break;
    case 't':
      runTopKFrequent();
      break;
    case 'm':
      runProductExceptSelf();
      break;
    case 'p':
      runPermutation();
      break;
    case 'd':
      runFindDuplicate();
      break;
    case 's':
      runSubset();
      break;
    case 'k':
      runKthLargest();
      break;
    case '3':
      runIncreasingTriplet();
      break;
    case 'l':
      runLIS();
      break;
    case 'c':
      runSortColors();
      break;
    case 'e':
      runFindPeakElement();
      break;
    case 'j':
      runJumpGame();
      break;
    case 'g':
      runLargestNumber();
      break;
    case 'x':
      runMaxProduct();
      break;
    case 'r':
      runSearchRotate();
      break;
    case 'b':
      runSearchRange();
      break;
    case 'w':
      runWiggleSort();
      break;
    case '1':
      runMaxConsecutiveOnes();
      break;
    case 'a':
      runMinCostClimbStair();
      break;
    case 'P':
      runPeakIndex();
      break;
    case 'I':
      runCheckNonDecreasing();
      break;
    case 'T':
      runThirdMax();
      break;
    case 'M':
      runMaxSlidingWindow();
      break;
    case 'S':
      runMinPairSum();
      break;
    case 'A':
      runSortArrayByParity();
      break;
    case 'f':
      runCanPlaceFlowers();
      break;
    case 'F':
      runFindUnsortedSubarray();
      break;
    case 'C':
      runCheckSubarraySum();
      break;
    case 'R':
      runSumRange();
      break;
    case 'K':
      runKthLargestInStream();
      break;
    case 'D':
      runSmallestRangeI();
      break;
    case 'G':
      runGroupSizeX();
      break;
    case 'u':
      runKdiffPair();
      break;
    case '0':
      runThreeSum();
      break;
    case 'o':
      runFirstMissingPositive();
      break;
    case 'n':
      runIsMonotonic();
      break;
    case '2':
      runSortArrayByParityII();
      break;
    case '=':
      runPivotIndex();
      break;
    default:
      usage();
      break;
  }

  return 0;
}
