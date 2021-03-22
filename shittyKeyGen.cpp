#include <iostream>
#include <string>

using namespace std;

string commandNameGenerator(string path,string name,bool isWindows){
  const string firstPart = "keytool -genkey -v -keystore ";
  const string secondPart = " -storetype JKS -keyalg RSA -keysize 2048 -validity 10000000000000 -alias key";
  string concatenatedPath = path + (isWindows ? "\\" : "/") + name + ".jks";
  string command = firstPart + concatenatedPath + secondPart;
  return command;
}

bool isWin(string os){
  string answer;
  bool correctAnswer;
  bool isWindows;
  do{
    cout << "Which OS are you using? (win,mac,linux) please type as shown(only lower case)" << endl;
    cin >> answer;
    if(answer == "win"){
      correctAnswer = true;
      isWindows = true;
    }else if(answer == "mac" || answer == "linux"){
      correctAnswer = true;
      isWindows = false;
    }else{
      correctAnswer = false;
    }
  }while(!correctAnswer);
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
  //change directory to the folder and print its contents
  string changeDirectoryCommand = "cd " + absolutePath;
  //Change directory
  system(changeDirectoryCommand.c_str());
  //Print directory contents
  system("dir");
  //Pause the program to prevent it from exiting and looking like an error
  system("pause");
}