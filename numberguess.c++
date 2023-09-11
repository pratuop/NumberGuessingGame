#include <iostream>
#include <fstream>
// #include <cstdlib>
#include <ctime>
#include <cstdlib>
using namespace std;
string username;
class user
{

public:
    int getnum;
    void getdata()
    {
        system("cls");

        // string id;
        cout << "\t\t\tNumber Guessing Game " << endl;
        cout << "=======================================================================" << endl;
        cout << "Enter Your Name:";

        cin >> username;
    }
    void menu()
    {
        string ch;
        system("cls");
        cout << "-------------------------------------------------------------------------" << endl;
        cout << "\t\t\tMain Menu" << endl;
        cout << "-------------------------------------------------------------------------" << endl;
        cout << "1]PLAY " << endl;
        cout << "2]SCORE BOARD " << endl;
        cout << "3]RULL" << endl;
        cout << "4]ABOUT" << endl;
        cout << "Enter Here:";
        cin >> getnum;
        if (getnum == 1)
        {
            system("cls");
        }
        else if (getnum == 2)
        {

            system("cls");
            ifstream inputFile("users.txt");
            cout << "----------------------------------------------------------------" << endl;
            cout << "\t\t\tSCORE BOARD" << endl;
            cout << "----------------------------------------------------------------" << endl;
            string cs;
            string line;

            while (getline(inputFile, line))
            {
                cout << line << endl;
            }

            inputFile.close();

            cout << "\nDO You want To play(Y/N)";
            cin >> cs;
            if (cs == "y" || cs == "Y")
            {
                system("cls");
                menu();
            }
            else
            {
                exit(0);
            }
        }
        else if (getnum == 3)
        {
            system("cls");
            cout << "-------------------------------------------------------------------------" << endl;
            cout << "\t\t\tRull" << endl;
            cout << "-------------------------------------------------------------------------" << endl;
            cout << "1)A number guessing game is a simple guessing game where a user is supposed \n to guess a number between 0 and N in a maximum of   10 attempts. " << endl;
            cout << "2)The game will end after 10 attempts and if the player failed to guess the \n number, and then he loses the game." << endl;
            cout << "Do You want to back Main Menu:(y/n)";
            cin >> ch;
            if (ch == "y" || "Y")
            {
                menu();
            }
            else
            {
                exit(0);
            }
            // menu();
        }
        else if (getnum == 4)
        {
            system("cls");
            ifstream inputFile("about.txt");
            cout << "----------------------------------------------------------------" << endl;
            cout << "\t\t\tABOUT US" << endl;
            cout << "----------------------------------------------------------------" << endl;
            string cs;
            string line;

            while (getline(inputFile, line))
            {
                cout << line << endl;
            }

            inputFile.close();

            cout << "\nDO You want To play(Y/N)";
            cin >> cs;
            if (cs == "y" || cs == "Y")
            {
                system("cls");
                menu();
            }
            else
            {
                exit(0);
            }
        }
    }
};
class game : public user
{

public:
    int score = 0;
    void play()
    {

        string conf;

        int user_choice = 0, val;

        //   cout << "Do You Want to continue(y/n) :";
        conf = "y";
        if (conf == "Y" || conf == "y")
        {
            srand((unsigned)time(0));
            int random_number = 1 + (rand() % 100);

            // cout<<random_number<<"\n";
            val = 1;
            cout << "\t\t\tGame Start" << endl;
            cout << "----------------------------------------------------------------------" << endl;
            cout << "Guess The Number Between 1 to 100:";
            //  cout << "Enter The Number:";
            cin >> user_choice;
            score = 1;
            while (val)
            {

                if (user_choice > random_number)
                {
                    cout << "Opps..! You Choose Wrong! Predicted Number is Smaller. Predict Again:";
                    cin >> user_choice;
                    score += 1;
                    // system("cls");
                }
                else if (user_choice < random_number)
                {
                    cout << "Opps..! You Choose Wrong! Predicted Number is  Greater. Predict Again:";
                    cin >> user_choice;
                    score += 1;
                }
                else if (user_choice == random_number)
                {
                    string us;
                    cout << "----------------------------------------------------------------------" << endl;
                    cout << "Congratulation " << endl;
                    cout << "----------------------------------------------------------------------" << endl;
                    cout << "Your Score is : " << score << endl;
                    val = 0;
                  //  cout << "Do You want to continue(Y/N)";
                  //  cin >> us;
                  //  if (us == "y" || us == "Y")
                  //  {
                        //   menu();
                  //  }
                    //  else
                    //  {
                    //      //    exit(0);
                    //  }
                }
                else
                {
                    exit(0);
                }
            }
        }
        else
        {
            exit(0);
        }
    }
    void userdata()
    {
        ofstream id("users.txt", ios::app);

        id << "USER_NAME:" + username << " SCORE:" << score << "\n";
        id.close();
    }
    void playgame()
    {
        user::getdata();
        user::menu();
        game::play();
        game::userdata();

        //  game::menu();
    }
};
int main()
{
    // user u;
    // game g;
    // g.play();
    // g.userdata()
    // u.getdata();
    game g;
    g.playgame();

    return 0;
}