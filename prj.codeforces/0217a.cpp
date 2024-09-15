// 271A красивый год
#include <iostream>
 
int main(){
  int x = 0;
  int i = 0;
  std::cin >> x;
  for (i = x+1; i < x+1000; ++i){
  int a = i / 1000;
  int b = i / 100 % 10;
  int c = i / 10 % 10;
  int d = i % 10;
  if (i > x && a != b && a != b && a != c && a != d && b != c && b != d && c != d) {
    std::cout << i;
    break;
    }
  }
}
