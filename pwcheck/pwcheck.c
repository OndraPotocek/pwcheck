#include <stdio.h>


int main(){
    char lowCaseEndCharacter[100] = "end";
    char upperCaseEndCharacter[3] = "END";
    int leaveingCharcker = 0;
    char password[100];

    printf("--------------------------------------------------\nWelcome to password checker program\nfor exit type END in any part of this program\n--------------------------------------------------\n");
    

    
    while(leaveingCharcker == 0){
        printf("password: ");
        scanf("%s", password);

        if (areEquals(password,lowCaseEndCharacter) == 1 || areEquals(password,upperCaseEndCharacter) == 1) return 1;

        

        
        
    }
    
}

int areEquals(char str1[],char str2[]){
    int chacker=0,i=0;

    while(str1[i]!='\0' && str2[i]!='\0'){
        if(str1[i]!=str2[i]){
            chacker = 1;
            break;
        }
        i++;

    }

    if(chacker == 0) return 1;
    else return 0;
}

