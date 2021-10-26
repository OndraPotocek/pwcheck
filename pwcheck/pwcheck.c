#include <stdio.h>
#include <stdbool.h>

#define COUNT_OF_ASCII 100



int containsLowAndUpperCharacter(char word[]){
    bool lowCharacer=false;
    bool upperCharacter = false;
    for(int i = 0;i<sizeof(word)/sizeof(word[0]);i++){
        if(word[i] >= 'a' && word[i] <='z'){
            lowCharacer=true;
        }
        if(word[i] >= 'A' && word[i] <='Z'){
            upperCharacter=true;
        }
    } 
    if(lowCharacer && upperCharacter){
        return 1;
    }   
    else{
        return 0;
    }
}

int havingRightCharset(char word[], int param){
    int checker = 0;
    bool lowNO=true,upNO=true,numNO=true,specNO=true;
    for(int i = 0;i<sizeof(word)/sizeof(word[0]);i++){
        if(word[i] >= 'a' && word[i] <='z' && lowNO){
            checker+=1;
            lowNO=false;
        }
        if(word[i] >= 'A' && word[i] <='Z' && upNO){
            checker+=1;
            upNO=false;
        }
        if(word[i] >= '0' && word[i] <='9' && numNO){
            checker+=1;
            numNO=false;
        }
        if((word[i] >= 32 && word[i] <= 47) || (word[i] >= 58 && word[i] <= 64) || (word[i] >= 91 && word[i] <= 96) || (word[i] >= 123 && word[i] <= 126) && specNO){
            checker+=1;
            specNO=false;
        }
    }
    if(param == 1 && checker>=1){
        return 1;
    }
    if(param == 2 && checker>=2){
        return 1;
    }
    if(param == 3 && checker>=3){
        return 1;
    }
    if(param == 4 && checker>=4){
        return 1;
    }
    
    
    return 0;
} 

bool notContainsSameChars(char word[], int param){
    if(param==1){
        return true;
    }
    if(param==2){
        for(int i = 0; i < sizeof(word)/sizeof(word[0])+param; i++){
            if(word[i]=='\0'){break;}
            if(word[i]==word[i+1]){return false;}
        }
    }
    if(param==3){
        for(int i = 0; i < sizeof(word)/sizeof(word[0])+param; i++){
            if(word[i]=='\0'){break;}
            if(word[i]==word[i+1]&&word[i]==word[i+2]){return false;}
        }
    }
    if(param==4){
        for(int i = 0; i < sizeof(word)/sizeof(word[0])+param; i++){
            if(word[i]=='\0'){break;}
            if(word[i]==word[i+1]&&word[i]==word[i+2]&&word[i]==word[i+3]){return false;}
        }
    }   
    return true;
    

}

int wordNChars(char pw[], char chars[]){
    bool newchar = true;
    int pointer = 0;
    int nChar = 0;
    for(int i = 0;i<sizeof(pw)/sizeof(pw[0]);i++){
        for(int j = 0; pw[j]!='\0';j++){
            if(pw[i] == chars[j]){
                newchar = false;
                pointer = j;
                break;
            }
            
        }
        if(newchar){
            chars[pointer] = pw[i];
            nChar+=1;
        }
    }
    return nChar;
}

int minimal(char pw[], int previousLength){
    int currentLenght = 0;
    for(int i = 0;i<sizeof(pw)/sizeof(pw[0]);i++){
        currentLenght++;
    }
    if(currentLenght<previousLength){
        return currentLenght;
    }
    else{
        return previousLength;
    }
}

int maximal(char pw[], int previousLength){
    int currentLength = 0;
    for(int i = 0;i<sizeof(pw)/sizeof(pw[0]);i++){
        currentLength++;
    }
    if(currentLength>previousLength){
        return currentLength;
    }
    else{
        return previousLength;
    }
}


bool notContainsSameStrings(char pw[], int delka)
{
    bool stejnePodretezce = true;
    switch (delka)
    {
        case 1: stejnePodretezce = false;
        case 2:
            {
                for (int i = 0; i < 100; i++)
                {
                    if (pw[i] == '\0')break;
                    for (int j = (1 + i); j < 100; j++)
                    {
                        if (pw[i] == pw[j])
                        {
                            if (pw[i+1] == pw[j+1]) stejnePodretezce = false;
                        }
                    }
                }
                break;
            }
        case 3:
            {
                for (int i = 0; i < 100; i++)
                {
                    if (pw[i] == '\0')break;
                    for (int j = (1 + i); j < 100; j++)
                    {
                        if (pw[i] == pw[j])
                        {
                            if ((pw[i+1] == pw[j+1]) && (pw[i+2] == pw[j+2]))stejnePodretezce = false;
                        }
                    }
                }
                break;
            }

        case 4:
            {
                for (int i = 0; i < 100; i++)
                {
                    if (pw[i] == '\0')break;
                    for (int j = (1 + i); j < 100; j++)
                    {
                        if (pw[i] == pw[j])
                        {
                            if ((pw[i+1] == pw[j+1]) && (pw[i+2] == pw[j+2]) && (pw[i+3] == pw[j+3]))stejnePodretezce = false;
                        }
                    }
                }
                break;
            }
    }
    return stejnePodretezce;
}
int main(int argc, char const *argv[]){
    int LEVEL = atoi(argv[1]);
    int PARAM = atoi(argv[2]);
    int nChars = 0;
    int min = 101;
    int max = 0;
    char pw[101];
    char chars[COUNT_OF_ASCII] = {0};
    while(fgets(pw, 101, stdin) != NULL){
        if(LEVEL == 1 && containsLowAndUpperCharacter(pw) == 1){
            printf("%s", pw);
        }
        if(LEVEL == 2 && containsLowAndUpperCharacter(pw) == 1 && havingRightCharset(pw, PARAM) == 1){
            printf("%s", pw);
        }
        if(LEVEL == 3 && containsLowAndUpperCharacter(pw) == 1 && havingRightCharset(pw, PARAM) == 1 && notContainsSameChars(pw, PARAM)){
            printf("%s", pw);
        }
        if(LEVEL == 4 && containsLowAndUpperCharacter(pw) == 1 && havingRightCharset(pw, PARAM) == 1 && notContainsSameChars(pw, PARAM) && notContainsSameStrings(pw, PARAM)){
            printf("%s", pw);
        }

        nChars+=wordNChars(pw,chars);
        min = minimal(pw,min);
    }

    printf("\nNCHAR: %d\nMinimalni delka: %d\nMaximalni delka: %d", nChars);
    



    
    
    return 0;
}
