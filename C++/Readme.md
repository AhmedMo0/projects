## Preview
This code works on two main Functions first one that take parameter in seconds and returns its value in time formate, the second function take a parameter in time formate
and returns its value in seconds

## Details
implementation of the first function:
void DigitalClockIntToStr(int seconds, char time[11]);
The function takes a first input parameter seconds which represents the number of elapsed
seconds from the previous midnight. The function should not modify this parameter. The
function takes a second output parameter time is a C-string that should contain 10
characters and one terminating null character representing the converted string from the
input parameter. Initially, it does not contain any specific string value, but the function is
responsible for computing its string value. Since the maximum number of seconds per day =
24*60*60 = 86400, the first integer parameter should be between 0 and 86399. If it is out of
this range, the function should set the second parameter to the string "invalid". The
following tables contain sample test cases for the expected function output given sample
inputs:
| seconds | 0          | 59         | 3600       | 86400   |
|---------|------------|------------|------------|---------|
| time[]  | 12:00:00am | 12:00:59am | 01:00:00am | invalid |

Then, include in the main() function test-calls to this function using the above test cases.
This is an example of testing the function using the first test case:
```cpp

// inside main()
char time[11];
DigitalClockIntToStr(0, time);
cout<<time<<endl;
// The previous line should print on screen: 12:00:00am

```

implementation of the second function:
int DigitalClockStrToInt(const char time[11]);
The function takes a first input parameter time is a C-string which represents the time
reported by Samy's clock. The function should not modify this parameter. The function must
return the number of elapsed seconds starting from the previous midnight to the given input
time. The following tables contain sample test cases for the expected function return value
given sample inputs:

| time[]       | 11:59:59am | 12:02:40am | 11:59:59pm | 01:01:06am |
|--------------|------------|------------|------------|------------|
| return value | 43199      | 160        | 86399      | 3666       |

Then, include in the main() function test-calls to this function using the above test cases.
This is an example of testing the function using the first test case:

```cpp
// inside main()
cout<< DigitalClockStrToInt("12:00:00am") <<endl;
// The previous line should print on screen: 0

```
