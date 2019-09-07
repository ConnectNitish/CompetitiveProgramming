/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <algorithm>
#include <limits.h>
#include <iterator>
#include <vector>
using namespace std;

template<typename T>
void print(T v)
{
    cout << v << " ";
}

bool debug = false;

class Solution
{
    
public : 
int firstMissingPositive(vector<int> &A); 
    
};

/* Utility function that puts all  
non-positive (0 and negative) numbers on left  
side of arr[] and return count of such numbers */
int segregate (vector<int> &arr, int size)  
{  
    int j = 0, i;  
    for(i = 0; i < size; i++)  
    {  
        if (arr[i] <= 0)  
        {  
            // swap(&arr[i], &arr[j]);  
            swap(arr[i],arr[j]);
            j++; // increment count of non-positive integers  
        }  
    }  
  
    return j;  
}  
  
/* Find the smallest positive missing number  
in an array that contains all positive integers */
int findMissingPositive(vector<int> &arr, int size)  
{  
    int i=0;  
      
    // Mark arr[i] as visited by making arr[arr[i] - 1] negative.  
    // Note that 1 is subtracted because index start  
    // from 0 and positive numbers start from 1  
    for(i = 0; i < size; i++)  
    {  
        if
        (
        // note that element which is encountered 
        // is in range of array size 
        abs(arr[i]) - 1 < size 
        && 
        // ensures that index is not visited before
        arr[ abs(arr[i]) - 1] > 0
        )  
        // mark the index value as negative 
        // showing it is visited first time 
        // if again same index came it will be negative 
        // means nothing to do since it is already visited 
        arr[ abs(arr[i]) - 1] = -arr[ abs(arr[i]) - 1];  
    }  
    
    if(debug)
    {
        cout << " Post Assigning Indexes for Postive Numbers " << endl;
        for_each(arr.begin(),arr.end(),print<int>);
        cout << endl;
    }
      
    // Return the first index value at which is positive  
    for(i = 0; i < size; i++)  
        if (arr[i] > 0)  
            // 1 is added because indexes start from 0  
            return i+1;  
      
    return size+1;  
}  
  
/* Find the smallest positive missing  
number in an array that contains  
both positive and negative integers */
int findMissing(vector<int> &arr, int size)  
{  
    // First separate positive and negative numbers  
    int shift = segregate (arr,size);  
    
    if(debug)
    {
        cout << " Post Shift " << endl;
        for_each(arr.begin(),arr.end(),print<int>);
        cout << endl << " No of Negative includeing zero " << shift <<  endl;
    }
    
    // Shift the array and call findMissingPositive for  
    // positive part  
    arr.erase(arr.begin(),arr.begin()+shift);
    
    if(debug)
    {
        cout << " Post Removing Negative numbers " << endl;
        for_each(arr.begin(),arr.end(),print<int>);
        cout << endl;
    }
    
    return findMissingPositive(arr, size - shift);  
}

int Solution::firstMissingPositive(vector<int> &A)
{
    int size = A.size();
    return findMissing(A,size);
}




int main()
{

    vector<int> D;
    copy(istream_iterator<int>(cin),istream_iterator<int>(),back_inserter(D));
    
    debug = true;
    
    cout << " Input " << endl;
    for_each(D.begin(),D.end(),print<int>);
    cout << endl;

    Solution s;
    cout << s.firstMissingPositive(D) << endl;
    
    return 0;
}

/*
Input 1 : 
417 929 845 462 675 175 73 867 14 201 777 407 80 882 785 563 209 261 776 362 730 74 649 465 353 801 503 154 998 286 520 692 68 805 835 210 819 341 564 215 984 643 381 793 726 213 866 706 97 538 308 797 883 59 328 743 694 607 729 821 32 672 130 13 76 724 384 444 884 192 917 75 551 96 418 840 235 433 290 954 549 950 21 711 781 132 296 44 439 164 401 505 923 136 317 548 787 224 23 185 6 350 822 457 489 133 31 830 386 671 999 255 222 944 952 637 523 494 916 95 734 908 90 541 470 941 876 264 880 761 535 738 128 772 39 553 656 603 868 292 117 966 259 619 836 818 493 592 380 500 599 839 268 67 591 126 773 635 800 842 536 668 896 260 664 506 280 435 618 398 533 647 373 713 745 478 129 844 640 886 972 62 636 79 600 263 52 719 665 376 351 623 276 66 316 813 663 831 160 237 567 928 543 508 638 487 234 997 307 480 620 890 216 147 271 989 872 994 488 291 331 8 769 481 924 166 89 824 -4 590 416 17 814 728 18 673 662 410 727 667 631 660 625 683 33 436 930 91 141 948 138 113 253 56 432 744 302 211 262 968 945 396 240 594 684 958 343 879 155 395 288 550 482 557 826 598 795 914 892 690 964 981 150 179 515 205 265 823 799 190 236 24 498 229 420 753 936 191 366 935 434 311 920 167 817 220 219 741 -2 674 330 909 162 443 412 974 294 864 971 760 225 681 689 608 931 427 687 466 894 303 390 242 339 252 20 218 499 232 184 490 4 957 597 477 354 677 691 25 580 897 542 186 359 346 409 655 979 853 411 344 358 559 765 383 484 181 82 514 582 593 77 228 921 348 453 274 449 106 657 783 782 811 333 305 784 581 746 858 249 479 652 270 429 614 903 102 378 575 119 196 12 990 356 277 169 70 518 282 676 137 622 616 357 913 161 3 589 327
Output 1 : 
1
*/

/*
Input 2 :
3 4 -1 1
Output 2 :

*/
