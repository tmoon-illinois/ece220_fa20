/*
 * Search for the substring "the"
 */
#include <stdio.h>

#define NO_MATCH 0
#define MATCH_t 1
#define MATCH_th 2

int main()
{
    char keyin;     // input character from keyboard
    int state=0;    // state 
    int count=0;    // number of matches
    printf("Enter a string: ");

    // your code here...

    do{
        scanf("%c", &keyin);
        switch(state){
            case NO_MATCH:
                if(keyin == 't'){
                    state = MATCH_t;
                }
                break;
            case MATCH_t:
                if(keyin == 'h'){
                    state = MATCH_th;
                }
                else if(keyin == 't'){
                }
                else{
                    state = NO_MATCH;
                }
                break;
            case MATCH_th:
                if(keyin == 't'){
                    state = MATCH_t;
                }
                else if(keyin == 'e'){
                    count++;
                    state = NO_MATCH;
                }
                else{
                    state = NO_MATCH;
                }
                break;
            default:
                break;
        }

    }while(keyin != '\n');
    
    printf("Number of matches = %d\n", count);
    return 0;
}







