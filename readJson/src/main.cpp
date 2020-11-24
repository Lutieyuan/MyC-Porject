#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>

using namespace std;

int main(int argc, char** argv) {
  // read the json file
  std::string json_filename = "multiObject.json";
  ifstream ifs(json_filename, ios::in);
  if (!ifs.is_open()) {
    cout << "Open file failed, please check the file: " << json_filename
         << endl;
    return 0;
  }
  // nlohmann::json j = nlohmann::json::parse(ifs);
  nlohmann::json j;
  ifs >> j;
  cout << j["output"]["crf"] << endl;
  int crf = j["output"]["crf"].get<int>();
  cout << crf << endl;
  cout << j["tracks"][0]["name"] << endl;
  cout << j["tracks"][0]["pieces"][0]["file"] << endl;
  ifs.close();

  // write to the json file
  std::string out_filename = "multiObject2.json";
  ofstream ofs(out_filename, ios::trunc);
  j["tracks"][0]["pieces"][0]["file"] = "multiObject2";
  ofs << j;
  ofs.close();

  return 0;
}