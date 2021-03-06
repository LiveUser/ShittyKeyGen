#include <iostream>
#include <string>

using namespace std;

string commandNameGenerator(string path,string name,bool isWindows){
  const string firstPart = "keytool -genkey -v -keystore ";
  const string secondPart = " -storetype JKS -keyalg RSA -keysize 2048 -validity 10000 -alias key";
  string concatenatedPath = path + (isWindows ? "\\" : "/") + name + ".jks";
  string command = firstPart + concatenatedPath + secondPart;
  return command;
}

bool isWin(string os){
  bool isWindows = false;
  #if _WIN64
    isWindows = true;
  #endif
  #if _WIN32
    isWindows = true;
  #endif
  return isWindows;
}

int main(){
  string absolutePath;
  string nameOfTheKey;
  string commandThatGeneratesTheKey;
  string os;
  bool usingWindows;
  //Welcome message
  cout << "Welcome to Shitty Key Generator" << endl;
  //Description
  cout << "The only key generator in the world that just runs the commands but doesn't actually generate the keys" << endl;
  cout << "------------------------------------------------------------------------------------------------------" << endl;
  //Ask for path
  cout << "Please enter the absolute path to where you want to store your generated key" << endl;
  cin >> absolutePath;
  //Ask for file name
  cout << "Please enter a name for your generated key" << endl;
  cin >> nameOfTheKey;
  //Ask for OS to try to support both platforms
  usingWindows = isWin(os);
  //Run the command to generate
  commandThatGeneratesTheKey = commandNameGenerator(absolutePath,nameOfTheKey,usingWindows);
  system(commandThatGeneratesTheKey.c_str());
  //TODO: Task complete notification
  cout << "Successfully created the key: " << nameOfTheKey << ".jks" << endl;
  cout << "At: " << absolutePath << endl;
  //Pause the program to prevent it from exiting and looking like an error
  system("pause");
}