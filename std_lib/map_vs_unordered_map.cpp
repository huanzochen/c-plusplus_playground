#include <iostream>
#include <map>
#include <string>


int main(){

    std::unordered_map<int, std::string> unorderedNames {{1, "anky"}, {2, "ashlinmorffy"}, {3, "kornocarge"}, {4, "kimberly"}};
  // print the unordered_map
  for(auto cur: unorderedNames){
    std::cout << cur.first << ": " << cur.second << std::endl;
  }
  std::cout << std::endl;

  std::map<int, std::string> orderedNames {{1,"tommy"}, {2,"kevin"}, {3, "alan"}, {4, "kimberly"}};

  // print the map
  for(auto cur: orderedNames){
    std::cout << cur.first << ": " << cur.second << std::endl;
  }
  std::cout << std::endl;


  std::map<int, std::string>::iterator itlow = orderedNames.lower_bound(2);
  if(itlow != orderedNames.end()){
    std::cout << "lower than 2, "  << itlow->first << ": " << itlow->second << std::endl;
  }

  std::map<int, std::string>::iterator itupper = orderedNames.upper_bound(2);
  if(itupper != orderedNames.end()){
    std::cout << "upper than 2, " << itupper->first << ": " << itupper->second << std::endl;
  }


}
