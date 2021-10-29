#include <stdio.h>
#include <stdbool.h>

#define COUNT_OF_ASCII 100



int containsLowAndUpperCharacter(char word[]){
    bool lowCharacer=false;
    bool upperCharacter = false;
    for(int i = 0;i<(sizeof(word)/sizeof(word[0]))+COUNT_OF_ASCII;i++){
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
    int low = 0, up = 0, num = 0, spec = 0;
    bool foundLow = false, foundUp = false, foundNum = false, foundSpec = false;
    for(int i = 0;i<(sizeof(word)/sizeof(word[0]))+COUNT_OF_ASCII;i++){
        if(word[i] == '\0'){
            break;
        }
        if(word[i] >= 'a' && word[i] <='z'){
            low = 1;
            
        }
        if(word[i] >= 'A' && word[i] <='Z'){
            up = 1;
            
        }
        if(word[i] >= '0' && word[i] <='9'){
            num = 1;
            
        }
        if((word[i] >= 32 && word[i] <= 47) || (word[i] >= 58 && word[i] <= 64) || (word[i] >= 91 && word[i] <= 96) || (word[i] >= 123 && word[i] <= 126)){
            spec = 1;
            
        }
        if(param == 1 && low + up + num + spec >= 1){
            return 1;
        }
        if(param == 2 && low + up + num + spec >= 2){
            return 1;
        }
        if(param == 3 && low + up + num + spec >= 3){
            return 1;
        }
        if(param == 4 && low + up + num + spec >= 4){
            return 1;
        }   
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
    int newChar = true;
    int newCharsCounter = 0;
    int pointer = 0;
    for(int i = 0;pw[i]!='\0';i++){
        for(int j = 0;chars[j]!=0;j++){
            pointer = j;
            if(pw[i]==chars[j]){
                newChar = false;
                break;
            }
        }
        if(newChar){
            newCharsCounter++;
            chars[pointer] = pw[i];
            
        }
        newChar = true;
    }
}

int minimal(char pw[], int previousLength){
    int currentLength = 0;
    for(int i = 1;pw[i]!='\0';i++){
        currentLength++;
    }
    if(currentLength<previousLength){
        return currentLength;
    }
    else{
        return previousLength;
    }

    
}

int maximal(char pw[], int previousLength){
    int currentLength = 0;
    for(int i = 1;pw[i]!='\0';i++){
        currentLength++;
    }
    if(currentLength>previousLength){
        return currentLength;
    }
    else{
        return previousLength;
    }
}


bool notContainsSameStrings(char word[], int param){
    bool notsamestrings = true;
        
    
    if(param == 2){
        for (int i = 0; i < COUNT_OF_ASCII; i++){
            if (word[i] == '\0'){
                break;
            }
            for (int j = i + 1; j < COUNT_OF_ASCII; j++){
                if (word[i] == '\0')
                    break;
                if (word[i] == word[j]){
                    if (word[i+1] == word[j+1]) 
                    notsamestrings = false;
                }
            }
        }
        
    }
    if(param == 3){
        for (int i = 0; i < COUNT_OF_ASCII; i++){
            if (word[i] == '\0'){
                break;
            }
            for (int j = i + 1; j < COUNT_OF_ASCII; j++){
                if (word[i] == '\0'){
                break;
            }
                if (word[i] == word[j]){
                    if ((word[i+1] == word[j+1]) && (word[i+2] == word[j+2]))
                    notsamestrings = false;
                }
            }
        }
        
    }

    if(param == 4){
        for (int i = 0; i < COUNT_OF_ASCII; i++){
            if (word[i] == '\0'){
                break;
            }
            for (int j = i + 1; j < COUNT_OF_ASCII; j++){
                if (word[i] == '\0'){
                break;
            }
                if (word[i] == word[j]){
                    if ((word[i+1] == word[j+1]) && (word[i+2] == word[j+2]) && (word[i+3] == word[j+3]))
                    notsamestrings = false;
                }
            }
        }
        
    }

    return notsamestrings;
}



int main(int argc, char const *argv[]){
    int LEVEL = atoi(argv[1]);
    int PARAM = atoi(argv[2]);
    char statsChar[] = "--stats";
    int nChars = 0;
    int min = 101;
    int currentLength = 0;
    char countOfChars[101] = {0};
    int n;
    bool stats = true;
    float wordCount = 0;
    float allCount = 0;
    float avg; 
    char pw[101];
    char chars[COUNT_OF_ASCII] = {0};

    if(argc < 2 || argc > 4){
        printf("Byl zadan nespravny pocet argumentu\n");
        return 0;
    }

    if((argv[1] < 1 && argv[1] >4) || (argv[2] < 1 && argv[2] > 4)){
        printf("Byly zadane nespravne hodnoty parametru\n");
        return 0;
    }

    while(fgets(pw, 101, stdin) != NULL){
        wordCount++;
        min = minimal(pw, min);
        
        if(LEVEL == 1 && containsLowAndUpperCharacter(pw) == 1){
            printf("\n%s\n", pw);
        }
        if(LEVEL == 2 && containsLowAndUpperCharacter(pw) == 1 && havingRightCharset(pw, PARAM) == 1){
            printf("\n%s\n", pw);
        }
        if(LEVEL == 3 && containsLowAndUpperCharacter(pw) == 1 && havingRightCharset(pw, PARAM) == 1 && notContainsSameChars(pw, PARAM)){
            printf("\n%s\n", pw);
        }
        if(LEVEL == 4 && containsLowAndUpperCharacter(pw) == 1 && havingRightCharset(pw, PARAM) == 1 && notContainsSameChars(pw, PARAM) && notContainsSameStrings(pw, PARAM)){
            printf("\n%s\n", pw);
        }
        
        int i = 0;
        while(pw[i] != '\0'){
            allCount++;
            i++;
        }
        

        for (int i = 0; i < COUNT_OF_ASCII; i++){
            if (pw[i] == '\0') {
                break;
            }
            for (int j = 0; j < COUNT_OF_ASCII; j++){
                if (countOfChars[j] == '\0'){
                    countOfChars[j] = pw[i];
                    break;
                }
                if (pw[i] == countOfChars[j]){
                    break;
                }
            }
        }
        
    }

    while(countOfChars[nChars] != '\0') {
        nChars++; 
    }

    n = 0; 
    while(statsChar[n]!='\0'){
        if(argv[3][n]!=statsChar[n])
            stats=false;
            
        n++;        
    }


    if(stats){
        avg = allCount/wordCount;
        printf("\n\n     STATISTIKA     \n--------------------\nNCHAR: %d\nMinimalni delka: %d\nPrumerna delka: %f\n--------------------\n", nChars,min,avg);
    }
    
    



    
    
    return 0;
}
