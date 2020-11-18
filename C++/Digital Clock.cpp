#include <iostream>


using namespace std;

void DigitalClockIntToStr(int seconds, char time[11]){

// variables initialization to start from second 0

int startHours = 3600, startMinuits = 60;
    int currentHour = 12, currentMinuit = 0, currentSecond = 0;
    string state = "am";



// End

// calculate time to get the hour, minute and second according the state of seconds

    if(seconds>=86400){
        char inv[] = "invalid";
        for(int i=0; i<sizeof(inv); i++){
            time[i]=inv[i];
        }
        //cout<<time<<endl;


    }else{

        //From midnight till before noon
        if(seconds< 60){
            currentSecond = seconds;

        }else if(seconds<3600 && seconds>= 60){
            currentMinuit = seconds / startMinuits;
            currentSecond = seconds % startMinuits;

        }else if(seconds<43200&& seconds>= 3600){
            currentHour = seconds / startHours;
            currentMinuit = (seconds % startHours) / startMinuits;
            currentSecond = (seconds % startHours) % startMinuits;

        //End

        // from noon till before midnight

        }else if(seconds>=43200 && seconds<86400){
            state = "pm";
            if(seconds==43200){currentHour = (seconds / startHours);
            }else{
            currentHour = (seconds / startHours) - 12 ;
            }
            currentMinuit = (seconds % startHours) / startMinuits;
            currentSecond = (seconds % startHours) % startMinuits;


        }


    //End

    //End

    // starting convert into string

        string str_currentHour ;
        string str_currentMinuit;
        string str_currentSecond;

        //convert hour to str

        if(currentHour<10){

                str_currentHour += currentHour + '0';
                str_currentHour = '0' + str_currentHour;

                }
        else{
            str_currentHour = ((currentHour/10) + '0');
            str_currentHour += ((currentHour%10) + '0' );

        }
        for(int i=0,j=0; i<2; ++i){
            time[i] = str_currentHour[j];
            j++;
        }

        //End

        time[2] = 58;    // set character ":"

        //convert minute to str

        if(currentMinuit<10){

                str_currentMinuit += currentMinuit + '0';
                str_currentMinuit = '0' + str_currentMinuit;

                }
        else{
            str_currentMinuit = ((currentMinuit/10) + '0');
            str_currentMinuit += ((currentMinuit%10) + '0' );

        }

        for(int i=3,j=0; i<5; ++i){
            time[i] = str_currentMinuit[j];
            j++;
        }

        //End

        time[5] = 58;   // set character ":"

        //convert second to str

        if(currentSecond<10){

                str_currentSecond += currentSecond + '0';
                str_currentSecond = '0' + str_currentSecond;

                }
        else{
            str_currentSecond = ((currentSecond/10) + '0');
            str_currentSecond += ((currentSecond%10) + '0' );

        }
        for(int i=6,j=0; i<8; ++i){
            time[i] = str_currentSecond[j];
            j++;
        }

        //End

        // write state in time string

        for(int i=8,j=0; i<10; ++i){
            time[i] = state[j];
            j++;
        }
        time[10]='\0';

        //End



    for(int i=0; i<10; ++i){
        cout<<time[i];

        }
        cout<<"\n";
    }


//End
}

int  DigitalClockStrToInt(const char time[11]){

string sState;

// get state of the clock

for(int i =8;i<10; i++){
    sState += time[i];
}

//End

int hour = 0;
int minute = 0;
int second = 0;
int sumTime = 0;

// turn str_hour into int_hour

for(int i=0;i<2;i++){
    if(time[0]=='0'){
        hour = time[++i] - '0';
        break;

        }else{
        hour = (time[0] - '0');
        hour *= 10;
    }
    hour += (time[i] - '0');

}

// end turn str_hour into int_hour

// turn str_minute into int_minute

for(int i=3;i<5;i++){
    if(time[3]=='0'){
        minute = time[++i] - '0';
        break;

        }else{
        minute = (time[3] - '0');
        minute *= 10;
    }
    minute += (time[i] - '0');

}

// end turn str_minute into int_minute

// turn str_second into int_second

for(int i=6;i<8;i++){
    if(time[6]=='0'){
        second = time[++i] - '0';
        break;

        }else{
        second = (time[6] - '0');
        second *= 10;
    }
    second += (time[i] - '0');
}
// end turn str_second into int_second

// time calculation
if(sState=="am" && hour==12){
    sumTime = (43200-(hour*3600)) + (minute*60) + second ;

}else{

    if(hour!= 12 && sState=="pm") hour += 12;
    sumTime = (hour*3600) + (minute*60) + second ;
}

cout<<"\n"<<sumTime<<endl; // will be deleted


}





int main()
{

    char time[11];

    // check DigitalClockIntToStr Function

    DigitalClockIntToStr(0, time);
    cout<<time<<endl;
    DigitalClockIntToStr(1, time);
    cout<<time<<endl;
    DigitalClockIntToStr(2, time);
    cout<<time<<endl;
    DigitalClockIntToStr(59, time);
    cout<<time<<endl;
    DigitalClockIntToStr(60, time);
    cout<<time<<endl;
    DigitalClockIntToStr(61, time);
    cout<<time<<endl;
    DigitalClockIntToStr(120, time);
    cout<<time<<endl;
    DigitalClockIntToStr(125, time);
    cout<<time<<endl;
    DigitalClockIntToStr(160, time);
    cout<<time<<endl;
    DigitalClockIntToStr(3600, time);
    cout<<time<<endl;
    DigitalClockIntToStr(3666, time);
    cout<<time<<endl;
    DigitalClockIntToStr(43199, time);
    cout<<time<<endl;
    DigitalClockIntToStr(43200, time);
    cout<<time<<endl;
    DigitalClockIntToStr(86399, time);
    cout<<time<<endl;
    DigitalClockIntToStr(86400, time);
    cout<<time<<endl;

    // check DigitalClockStrToInt Function

    cout<<DigitalClockStrToInt("12:00:00am")<<endl;
    cout<<DigitalClockStrToInt("12:00:01am")<<endl;
    cout<<DigitalClockStrToInt("12:00:02am")<<endl;
    cout<<DigitalClockStrToInt("12:00:59am")<<endl;
    cout<<DigitalClockStrToInt("12:01:00am")<<endl;
    cout<<DigitalClockStrToInt("12:01:01am")<<endl;
    cout<<DigitalClockStrToInt("12:02:00am")<<endl;
    cout<<DigitalClockStrToInt("12:02:05am")<<endl;
    cout<<DigitalClockStrToInt("12:02:40am")<<endl;
    cout<<DigitalClockStrToInt("01:00:00am")<<endl;
    cout<<DigitalClockStrToInt("01:01:06am")<<endl;
    cout<<DigitalClockStrToInt("11:59:59am")<<endl;
    cout<<DigitalClockStrToInt("12:00:00pm")<<endl;
    cout<<DigitalClockStrToInt("11:59:59pm")<<endl;


    return 0;
}
