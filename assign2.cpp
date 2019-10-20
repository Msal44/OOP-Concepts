//this was given to us students on class
//But waht the main() does is grabs teamData and gameData.txt and returns it so that we can get our output
//the output can be found in the other files

int main(){
        Team Team1("teamData");
        Team1.print();

        Team1.processGameData("gameData.text");
        Team1.print();

        return 0;
}
