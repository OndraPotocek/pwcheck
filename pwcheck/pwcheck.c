#include <stdio.h>


#define LEVEL 3
#define PARAM 2

int containsLowAndUpperCharacter(char word[]){
    int lowCharacerCounter = 0;
    int upperCharacterCounter = 0;
    for(int i = 0;i<sizeof(word)/sizeof(word[0]);i++){
        if(word[i] >= 'a' && word[i] <='z'){
            lowCharacerCounter+=1;
        }
        if(word[i] >= 'A' && word[i] <='Z'){
            upperCharacterCounter+=1;
        }
    } 
    if(lowCharacerCounter > 0 && upperCharacterCounter >0){
        return 1;
    }   
    else{
        return 0;
    }
}

int havingRightCharset(char word[], int param){
    int lowFound=0,upperFound=0,numFound=0,specFound=0;
    for(int i = 0;i<sizeof(word)/sizeof(word[0]);i++){
        if(word[i] >= 'a' && word[i] <='z'){
            lowFound+=1;
        }
        if(word[i] >= 'A' && word[i] <='Z'){
            upperFound+=1;
        }
        if(word[i] >= '0' && word[i] <='9'){
            numFound+=1;
        }
        if((word[i] >= 32 && word[i] <= 47)&&(word[i] >= 58 && word[i] <= 64)&&(word[i] >= 91 && word[i] <= 96)&&(word[i] >= 123 && word[i] <= 126)){
            specFound+=1;
        }
    }
    if(param <= 1){
        if(lowFound>0){
            return 1;
        }
    }
    if(param == 2){
        if(lowFound>0 && upperFound>0){
            return 1;
        }
    }
    if(param == 3){
        if(lowFound>0 && upperFound>0 && numFound>0){
            return 1;
        }
    }
    if(param >= 4){
        if(lowFound>0 && upperFound>0 && numFound>0 && specFound>0){
            return 1;
        }
    } 
    return 0;
} 

int notContainsSameChars(char word[], int param){
    int helper = 0;
    if(param == 1){
        return 1;
    }
    for(int i = 1;i<(sizeof(word)/sizeof(word[0]))+1;i++){
        if(word[i] == word[i-1]){
            helper+=1;
        }
        if(helper == param){
            return 0;
        }
    }
    return 1;
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
