#include <iostream>
int main()
{
  std::cout<<"/*";
  std::cout<<"*/";
  //std::cout<</*"*/"*/; 
  std::cout<<std::endl;
  int i = 1;
  int sum = 0;
  while(i<10)
  {
    sum+=i;
    i++; 
  }
  std::cout<<sum<<std::endl;
  return 0;
}
