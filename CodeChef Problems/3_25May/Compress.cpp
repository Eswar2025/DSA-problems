//Tip: press alt + z (for wrapping the text)
//Tip: Close the left panel and keep the Question in right half of page and code in the left half portion

#include <iostream>

using namespace std;

int main()  {
    /* I want you to write the complete code for this Question and if you want any hints then scroll down this page */
    int t;
    cin>>t;
    while(t--){
        //Start from here and in terminal give the sample 1 inputs (from Question screenShot)
    }
    return 0;
}




























































/* Hint-1: 
Chefs video has N frames. The value of the frame is Ai. We have to find out the minimum size to which he can compress the video given
the following operations
• Choose an index i such that the value of the frame is equal to the value of either of its neighbors and remove the frame
• Chef can do the above operation any number of times
Can the following help us solve this problem?
• Can we list some examples which can help us solve this problem?
• Once we identify the sets of similar numbers, how do we identify how many can be deleted from them?

Hint-2:
->   N = 10 and Video = [1 1 2 2 1 1 1 2 2 2]
        Here, the frames can be compressed to [1 2 1 2] with a length of 4
->    N = 10 and Video = [1 1 2 2 3 4 5 6 7 7]
        Here, the frames can be reduced to [1 2 3 4 5 6 7] with a length of 7

Hint-3:
We need to identify adjacent groupings of every number. Once we identify the grouping, it doesn't matter how many repetitions there are,
they will reduce down to 1 instance of this number. How do we program this?
We should maintain a counter - count and run a loop from the list across all elements
If Video[t) = Video[i+l], then wejust do i = i+l
Else if Video[i) Not equal to Video[i+l], then we do count = count + 1 and i= i+l
Through this operation, we are trying to identify the number of unique number groupings in the video list
Once we complete the loop, we output count
*/








/* 
My method of approach:
#include <stdio.h>

int main() {
   
    int t;
    scanf("%d", & t);
    while (t--) {
        int n, val1, val2, answer = 0;
        scanf("%d", & n);
        for (int i = 0; i < n; i++) {
            if (i != 0) {
                scanf("%d", & val2);
                if (val1 == val2)
                    answer++;
                val1 = val2;
            } else
                scanf("%d", & val1);
            }
        printf("%d\n", n - answer);
    }
    return 0;
}
            */