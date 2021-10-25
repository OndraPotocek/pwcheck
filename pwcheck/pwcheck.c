#include <stdio.h>
#include <stdbool.h>


#define LEVEL 3
#define PARAM 3

bool areEquals(char word1[], char word2[]){
    
    int chacker=0,i=0;

    while(word1[i]!='\0' || word2[i]!='\0'){
        if(word1[i]!=word2[i]){
            chacker = 1;
            break;
        }
        i++;

    }

    if(chacker == 0){
        return true;
    }
    else{
        return false;
    }


        
    
}

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
        for(int i = 0; i < sizeof(word)/sizeof(word[0]+param); i++){
            if(word[i]=='\0'){break;}
            if(word[i]==word[i+1]){return false;}
        }
    }
    if(param==3){
        for(int i = 0; i < sizeof(word)/sizeof(word[0]+param); i++){
            if(word[i]=='\0'){break;}
            if(word[i]==word[i+1]&&word[i]==word[i+2]){return false;}
        }
    }
    if(param==4){
        for(int i = 0; i < sizeof(word)/sizeof(word[0]+param); i++){
            if(word[i]=='\0'){break;}
            if(word[i]==word[i+1]&&word[i]==word[i+2]&&word[i]==word[i+3]){return false;}
        }
    }   
    return true;
    

}

/*int notContainsSameStrings(char word[], int param){

}*/

int main(int argc, char const *argv[]){
    char pw[101];
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
        if(LEVEL == 4 && containsLowAndUpperCharacter(pw) == 1 && havingRightCharset(pw, PARAM) == 1 && notContainsSameChars(pw, PARAM)){
            printf("%s", pw);
        }
    }
    
    
    return 0;
}
