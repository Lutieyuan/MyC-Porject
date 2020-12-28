#include "speechManager.h"

SpeechManager::SpeechManager() {
  // init the speech competition
  this->init_Speech();
  // create the speakers
  this->create_Speaker();
}

SpeechManager::~SpeechManager() {}

void SpeechManager::show_Meun() {
  cout << "**************************************************" << endl;
  cout << "**** Welcome to the Speech Competition system ****" << endl;
  cout << "**** 1. Start the speech competition *************" << endl;
  cout << "**** 2. Look out the competition record***********" << endl;
  cout << "**** 3. Empty the competition record *************" << endl;
  cout << "**** 0. Exit the competition system **************" << endl;
  cout << "**************************************************" << endl;
  cout << endl;
}

void SpeechManager::exit_System() {
  cout << "Welcome for the next time" << endl;
  cout << "Press any key and \"Enter\" to exit" << endl;
  string a;
  cin >> a;
  system("clear");
  exit(0);
}

void SpeechManager::init_Speech() {
  // set the container empty
  this->v1.empty();
  this->v2.empty();
  this->vVictory.empty();
  this->m_Speaker.empty();

  // init the index of the speech epoch
  this->m_Index = 1;
}

void SpeechManager::create_Speaker() {
  string nameSeed = "ABCDEFGHIJKL";
  for (int i = 0; i < nameSeed.size(); i++) {
    string name = "Speaker_";
    name = name + nameSeed[i];
    // initialize each speaker
    Speaker sp;
    sp.SetName(name);
    double init_score[2] = {0, 0};
    sp.SetSocre(init_score);
    // initialize the speaker's ID
    this->v1.push_back(i + 1001);
    // put the speaker into map with its ID
    this->m_Speaker.insert(make_pair(i + 1001, sp));
  }
}

class intPrint1 {
 public:
  void operator()(int val) { cout << val << " "; };
};
void intPrint2(int val) { cout << val << " "; }

void SpeechManager::speechDraw() {
  cout << "The speakers of the " << this->m_Index << "-th epoch are drawing"
       << endl;
  cout << "The order of the darwing is following: " << endl;
  if (this->m_Index == 1) {
    random_shuffle(this->v1.begin(), this->v1.end());
    for_each(v1.begin(), v1.end(), intPrint1());
  } else {
    random_shuffle(this->v2.begin(), this->v2.end());
    for_each(v2.begin(), v2.end(), intPrint2);
  }
  cout << endl << "-------------------" << endl;
}

void SpeechManager::startSpeech() {
  // ***** 1st epoch  *****
  // 1. draw
  this->speechDraw();
  // 2. compete
  this->speechContest();
  // 3. show the upgrade result

  //
}

void SpeechManager::speechContest() {
  cout << "The " << this->m_Index << "-th epoch start" << endl;
  // An container to save the maping of the temp competing group and its score
  multimap<double, int, greater<double> /* */>
      groupScore;     // the <double,int,greater<double>> are correspoind to the
                      // score, ID, and built-in functional sort order
  int num = 0;        // the num of speakers in the current group
  vector<int> v_Src;  // the container for the competing speakers
  if (this->m_Index == 1) {
    v_Src = this->v1;

  } else {
    v_Src = this->v2;
  }
  // visit every speaker to compete
  for (vector<int>::iterator it = v_Src.begin(); it != v_Src.end(); it++) {
    num++;
    // each reviewer give the score of every speaker
    deque<double> d;
    for (int i = 0; i < 10; i++) {
      double score = (rand() % 401 + 600) / 10.f;  // 600~1000
      // cout << score << "\t";
      d.push_back(score);
    }
    // cout << endl;
    sort(d.begin(), d.end(),
         greater<double>());  // sort the scores by built-in
                              // functional greater<double>()
    d.pop_back();             // remove the minimum score
    d.pop_front();            // remove the maxmum score

    double sum = accumulate(d.begin(), d.end(), 0.0f);  // sum the scores
    double ave = sum / d.size();                        // get the average score

    // assign the average score into the map
    this->m_Speaker[*it].SetEpochSocre(ave, this->m_Index - 1);
    // print the average score
    // cout << "ID: " << *it << " Name: " << this->m_Speaker[*it].GetName()
    //      << " Ave Score:" << this->m_Speaker[*it].GetSocre()[this->m_Index -
    //      1]
    //      << endl;

    // save the average score and ID  in groupScore
    groupScore.insert(make_pair(ave, *it));
    // take the first three speakers of each group by average scores
    if (num % 6 == 0) {  // seperate each group by mod 6
      cout << "The " << num / 6 << "-th group scores:" << endl;
      for (multimap<double, int, greater<double> /* */>::iterator it =
               groupScore.begin();
           it != groupScore.end(); it++) {
        cout << "ID: " << it->second
             << " Name: " << this->m_Speaker[it->second].GetName() << " Score: "
             << this->m_Speaker[it->second].GetSocre()[this->m_Index - 1]
             << endl;
      }
      // take in the first three speakers into the next epoch
      int count = 0;
      for (multimap<double, int, greater<double> /* */>::iterator it =
               groupScore.begin();
           it != groupScore.end() & count < 3; it++, count++) {
        if (this->m_Index == 1) {
          this->v2.push_back(it->second);
        } else {
          this->vVictory.push_back(it->second);
        }
      }
      groupScore.clear();  // empty the temp score group
      cout << endl;
    }
  }
  cout << "-----The " << this->m_Index << "-th epoch finished------" << endl;
}