#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <set>
#include "fmt/ranges.h"
#define GETMAX
#define GETMIN

void show(std::vector<int> vec);
void show2(std::vector<double> vec);
void show3(std::vector<std::string> vec);
std::vector<int> sort_bigger_half(std::vector<int> vec);
std::vector<double> erase_n_biggest(std::vector<double> vec, int n);
std::vector<double> erase_n_biggest2(std::vector<double> v, int n);
std::vector<double> erase_between_minmax(std::vector<double> vec);
std::vector<int> exchange_boundaries(std::vector<int> vec);
void task2_2();
int maxNestedParenthesesDepth(std::string str);
enum class VERSION{EVEN, ODD,PRIME};
std::vector<int> remove_if_enum(std::vector<int> vec, VERSION version);
auto isEven (int vec) -> bool;
bool isPrime (int v);
std::vector<std::string> move_by_vowels(std::vector<std::string> vec);
std::pair<std::vector<int>, std::vector<int>> split_vector(std::vector<int>& vec);
double compute_median(const std::vector<int> vec);
std::vector<std::string> filter(std::vector<std::string> vec, std::set<std::string> set);

int main() {
    //Task 1
    std::vector<int> input = {2, 3, 5, 9, 1, 3, 7, 9, 2};
    //std::vector<double> input2 = {2, 1, 5, 4, 6, 3, 7, 9, 9};
    show(input);
    //show(sort_bigger_half(input));
    //show2(erase_n_biggest(input2, 3));
    //show2(erase_n_biggest2(input2,5));
    //show2(erase_between_minmax(input2));
    //show(exchange_boundaries(input));
    //task2_2();
    /*std::cout << maxNestedParenthesesDepth("()") << ' '
              << maxNestedParenthesesDepth("(()(()))") << ' '
              << maxNestedParenthesesDepth("(sd()ds((ss))  a)") << ' '
              << maxNestedParenthesesDepth("(((S)))") << ' '
              << maxNestedParenthesesDepth("()()()()") << ' '
              << maxNestedParenthesesDepth("()(())()");
              */
    //std::cout<<std::endl;
    //show(remove_if_enum(input, VERSION::PRIME));
    //std::vector<std::string> inputString = {"Armor", "Salon", "Mary", "Eury", "Lia", "arm" };
    //show3(inputString);
    //show3(move_by_vowels(inputString));
    //split_vector(input);
    std::ranges::partition(input, [](int x) -> bool{return x%2!=0;});
    fmt::print("{}\n", input);
/*bool isEven (int vec){
    return vec%2==0;
}*/

    std::vector<int> vec = {1,2,3,4,3,6,3,8};
    fmt::print("{}\n", vec);
    fmt::print("{0} {0}\n", vec);
    auto x = 5;
    fmt::print("{0} !!!{1}!!!\n", vec, x);
    auto numberOf3s = std::ranges::count(vec, 3);
    fmt::print("{}\n", numberOf3s);
    auto numberOfEven = std::ranges::count_if(vec, isEven);
    fmt::print("{}\n", numberOfEven);
    auto functionIsEven = [] (int vec) -> bool {
        return vec%2==0;
    };
    auto numberOfEven2 = std::ranges::count_if(vec, functionIsEven);
    fmt::print("{}\n", numberOfEven2);
    auto numberOfEven3 = std::ranges::count_if(vec, [] (int vec) -> bool {return vec%2==0;});
    fmt::print("{}\n", numberOfEven3);
    auto numberOfEven4 = std::ranges::count_if(vec, [] (int vec) {return vec%2==0;});
    fmt::print("{}\n", numberOfEven4);
    //std::ranges::remove_if(vec, [](int x) -> bool{return x%2!=0;});
    //fmt::print("{}\n", vec);
    std::ranges::partition(vec, [](int x) -> bool{return x%2!=0;});
    fmt::print("{}\n", vec);


    auto vec3 = std::vector<int>{3,4,2,5,6,1};
    auto set = std::set<int>(vec3.begin(), vec3.end());
    vec3.erase(vec3.begin(), vec3.end());
    for (auto s: set) {
        vec3.push_back(s);
    }

    for(auto e : vec3){
        std::cout << e << ' ';
    }

    auto vec4 = std::vector<std::string>{"l","m","f","r","a","m"};
    auto set2 = std::set<std::string>{"l","u","f","i","a","p"};
    show3(filter(vec4,set2));

}
//useful in general

void show(std::vector<int> vec) {
    for (int i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
}

void show2(std::vector<double> vec) {
    for (int i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
}
void show3(std::vector<std::string> vec) {
    for (int i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
}

// TUTORIAL 1

//Task 1
std::vector<int> sort_bigger_half(std::vector<int> vec) {
    int sum1 = 0, sum2 = 0;
    for (int i = 0; i < vec.size() / 2; i++) {
        sum1 += vec.at(i);
    }
    for (int i = vec.size() / 2; i < vec.size(); i++) {
        sum2 += vec.at(i);
    }
    if (sum1 > sum2) {
        std::ranges::sort(vec.begin(), vec.begin() + vec.size() / 2);
    } else {
        std::ranges::sort(vec.begin() + vec.size() / 2, vec.end());
    }
    return vec;
}

//Task 2
std::vector<double> erase_n_biggest(std::vector<double> vec, int n) {
    std::vector<double> empty;
    if (vec.size() <= n) {
        return empty;
    } else {
        for (int i = 0; i < n; i++) {
            vec.pop_back();
        }
        return vec;
    }
}
//actual good solution
std::vector<double> erase_n_biggest2(std::vector<double> v, int n){
    for(int i=0;i<n;i++){
        v.erase(std::ranges::max_element(v.begin(),v.end()));
    }
    return v;
}

//Task 3
std::vector<double> erase_between_minmax(std::vector<double> vec){
    vec.erase(std::ranges::min_element(vec.begin(), vec.end()),
              std::ranges::max_element(vec.begin(), vec.end()));
    return vec;
}

//Task 4
std::vector<int> exchange_boundaries(std::vector<int> vec){
    std::ranges::iter_swap(std::max_element(vec.begin(),vec.end()),std::min_element(vec.begin(), vec.end()));
    return vec;
}

// TUTORIAL 2

//Task 1
void task2_1() {
    std::vector<int> vec = {1, 2, 3, 4, 5, 6, 7};

#ifdef GETMAX
    std::cout << "MAX -> " << std::ranges::max(vec) << std::endl;;
#endif

#ifdef GETMIN
    std::cout << "MIN -> " << std::ranges::min(vec) << std::endl;
#endif

#ifndef GETMAX
    #ifndef GETMIN
    #error
#endif
#endif
}

//Task BMI

void task2_2 (){
    double m;
    double h;
    std::cout << " Mass in kg : ";
    std::cin >> m;
    std::cout << "Height in meters : ";
    std::cin >> h;
    std::cout<< "BMI equals : "<< m/(h*h) << std::endl;
}

//TASK 2

void problem2_2(double a, double b, double c) {
    //Write a program solving quadratic equations (ax2+bx+c= 0) given the coefficientsa,bandc.
    //The program should work in all cases (in particular, when coefficientsare 0 or the discriminant is negative).
    std::cout << " for x: " << std::endl;
    double d = b * b - 4 * a * c;
    double x1;
    double x2;
    if (d < 0) {
        d /= -1;
        double tmp = abs(sqrt(d) / (2 * a));
        std::cout << -b / (2 * a) << " + " << tmp << " * i" << std::endl;
        std::cout << -b / (2 * a) << " - " << tmp << " * i" << std::endl;
    }
    else {
        x1 = (-b + sqrt(d)) / (2 * a);
        x2 = (-b - sqrt(d)) / (2 * a);
        if (x1 != x2) std::cout << x1 << std::endl;
        std::cout << x2 << std::endl;
    }
}

//TASK 3

void problem2_3() {
    /*Write a program reading integers until zero is entered and printing the length of the
    longest sequence of consecutive numbers of the same value (and this value).
    For example, for
    22 22 22 22 3 3 3 2 -6 -6 -6 0
    the result should be
    Longest sequence: 4 times 22
    Do not use arrays, strings or any other kind of collections.*/
    int a;
    int countMax = 1;
    int count = 1;
    std::cout << "number: ";
    std::cin >> a;
    int aMax = a;
    while (a != 0) {
        int temp = a;
        std::cout << "number: ";
        std::cin >> a;
        if (temp == a) {
            count++;
            if (count > countMax) {
                countMax = count;
                aMax = a;
            }
        }
        else count = 1;
    }
    std::cout << "Longest sequence: " << countMax << " times " << aMax << std::endl;
}

//TASK 4
void problem2_4() {
    /*Write a program which reads in a loop a sequence of integral numbers until the user
    enters 0, which just signals the end of data and is not then taken into account. After
    that, the program prints the value of the smallest and the largest element of the
    sequence and the number of occurrences of these values in the whole sequence.
    For example, for the sequence (7,3,-24,2,7,-24,7,2,0) the program should print:
    Min = -24 2 times
    Max = 7 3 times
    Note: do not use arrays or any other collections!*/
    int a;
    int countMax = 1;
    int countMin = 1;
    std::cout << "number: ";
    std::cin >> a;
    int max = a;
    int min = a;
    while (a != 0) {
        int temp = a;
        std::cout << "number: ";
        std::cin >> a;
        if (a == 0) break;
        if (a > max) {
            max = a;
            countMax = 1;
        } else if (a == max)
            countMax++;
        else if (a < min) {
            min = a;
            countMin = 1;
        } else if (a == min)
            countMin++;
    }
    std::cout << "Min = " << min << " " << countMin << " times" << std::endl;
    std::cout << "Max = " << max << " " << countMax << " times" << std::endl;
}

//TASK 5
int gcdRec(int a, int b) {
    //returns the greatest common divisor of two natural(positive, integral) numbers
    int tmp = b;
    b = a % b;
    a = tmp;
    if (b == 0) return a;
    return gcdRec(a, b);
}
int sumDigits(int n) {
    //returns the sum of(decimal) digits of a given natural number(e.g., 34->7)
    int sum = n % 10;
    n /= 10;
    if (n == 0) return sum;
    else return sum + sumDigits(n);
}
int numDigits(int n) {
    //returns the number of (decimal) digits of a given natural number(e.g., 34->2)
    int sum = 1;
    if (n < 10) return sum;
    else return sum + numDigits(n / 10);
}
void printOddEven(int n) {
    /*prints in one line
    – if n is even – all even numbers starting from 2 up to and including n;
    – if n is odd – all odd numbers starting from 1 up to and including n;*/
    if (n % 2 == 0) {
        if (n > 2) printOddEven(n - 2);
    }
    else if (n > 1) printOddEven(n - 2);
    std::cout << n << " ";
}
void hailstone(int n) {
    /*prints in one line all numbers of the Collatz sequence (see below) from n to 1.
    Collatz sequence, also known as Ulam or hailstone sequence, starts with a positive
    integer a0 and subsequent elements are calculated according to formula
    an+1 = (1/2 * an if an is even,
            1 + 3an if an is odd.)
    Collatz conjecture (still unproven) states that for any positive integer a0 the sequence
    will eventually reach 1 (and then will cycle 1->4->2->1. . . indefinitely).*/
    std::cout << n << " ";
    if (n == 1)
        std::cout << "4 2 1 ..." << std::endl;
    else {
        if (n % 2 == 0) {
            hailstone(n / 2);
        }
        else {
            hailstone(1 + 3 * n);
        }
    }
}
void problem2_5() {
    /*Write and test the following set of recursive functions (there must not be any loops
    in their body; in the first three, even the if statements should not be necessary)*/
    int a = 12;
    int b = 4;
    std::cout << " GCD of " << a << " and " << b << " is " << gcdRec(a, b) << std::endl;
    std::cout << "Sum of digits of " << a << " is " << sumDigits(a) << std::endl;
    std::cout << "Number of digits of " << a << " is " << numDigits(a) << std::endl;
    std::cout << "Odd/Even numbers >= " << a << std::endl;
    printOddEven(a);
    std::cout << std::endl;
    std::cout << "Collatz sequence of " << a << std::endl;
    hailstone(a);
    std::cout << std::endl;
}

// TUTORIAL 3

//TASK 1
int maxNestedParenthesesDepth(std::string str) {
    int max_depth = 0;
    int current_depth = 0;

    for (char c : str) {
        if (c == '(') {
            current_depth++;
            if (current_depth > max_depth) {
                max_depth = current_depth;
            }
        } else if (c == ')') {
            if (current_depth > 0) {
                current_depth--;
            } else {
                return -1;  // unbalanced parentheses
            }
        }
    }

    if (current_depth != 0) {
        return -1;  // unbalanced parentheses
    }

    return max_depth;
}

//TASK 2

auto isEven (int vec) -> bool {
    return vec%2==0;
}
bool isPrime(int n) {
    if (n <= 2) return false;
    for (int i = 2; i <= std::sqrt(n); i++) {
        if (n % i == 0) return false;
    }
    return true;
}

std::vector<int> remove_if_enum(std::vector<int> vec, VERSION version){
    switch(version){
        case VERSION::EVEN : vec.erase(std::remove_if(vec.begin(), vec.end(), [](int n){ return n%2 == 0; }), vec.end());
            return vec;
        case VERSION::ODD: vec.erase(std::remove_if(vec.begin(), vec.end(), [](int n){ return n%2 == 0; }), vec.end());
            return vec;
        case VERSION::PRIME:   {
            std::vector<int> non_primes;
            non_primes.reserve(vec.size());
            for (int n : vec) {
                if (!isPrime(n)) {
                    non_primes.push_back(n);
                }
            }
            return non_primes;
        }
    }
}

//TASK 3
bool starts_with_vowel(const std::string s) {
    char first_char = tolower(s[0]);
    return (first_char == 'a' || first_char == 'e' || first_char == 'i' || first_char == 'o' || first_char == 'u');
}
std::vector<std::string> move_by_vowels(std::vector<std::string> vec){
    auto partition_point = std::partition(vec.begin(), vec.end(), starts_with_vowel);
    std::sort(vec.begin(), partition_point);
    std::sort(partition_point, vec.end());
    return vec;
}

//TASK 4
double compute_median(const std::vector<int> vec) {
    std::vector<int> temp(vec); // make a copy of the input vector
    auto middle = temp.begin() + temp.size() / 2;
    std::nth_element(temp.begin(), middle, temp.end());
    if (temp.size() % 2 == 0) {
        auto middle1 = middle - 1;
        return (double)(*middle + *middle1) / 2.0;
    } else {
        return (double)*middle;
    }
}
std::pair<std::vector<int>, std::vector<int>> split_vector(std::vector<int>& vec) {
    auto middle = std::partition(vec.begin(), vec.end(), [&vec](int x){ return x < compute_median(vec); });
    std::vector<int> first_half(vec.begin(), middle);
    std::vector<int> second_half(middle, vec.end());
    return std::make_pair(first_half, second_half);
}

// TUTORIAL 4

// TASK 1

/*
   auto vec3 = std::vector<int>{3,4,2,5,6,1};
    auto set = std::set<int>(vec3.begin(), vec3.end());
    vec3.erase(vec3.begin(), vec3.end());
    for (auto s: set) {
        vec3.push_back(s);
    }

    for(auto e : vec3){
        std::cout << e << ' ';
    }

}
 */

// TASK 2
std::vector<std::string> filter(std::vector<std::string> vec, std::set<std::string> set){
   std::vector<std::string> vec2;
    for(int i = 0; i< vec.size(); i++){
      if (!(set.find(vec[i]) != set.end())){
          vec2.push_back(vec[i]);
        }
    }
    return vec2;
}

// TASK 3

/*
 #include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

int main() {
    std::map<size_t, std::vector<std::string>> groups;
    std::string word;
    std::cout << "Enter words (enter 'stop' to finish):\n";
    while (std::cin >> word && word != "stop") {
        auto len = word.length();
        if (len > 0) {
            groups[len].push_back(word);
        }
    }
    for (const auto& [len, group] : groups) {
        std::vector<std::string> uniqueGroup = group;
        std::sort(uniqueGroup.begin(), uniqueGroup.end());
        auto last = std::unique(uniqueGroup.begin(), uniqueGroup.end());
        uniqueGroup.erase(last, uniqueGroup.end());
        for (const auto& word : uniqueGroup) {
            std::cout << word << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}

 */
