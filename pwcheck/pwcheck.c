#include <stdio.h>
#include <stdbool.h>


#define COUNT_OF_ASCII 100


// First condition (LVL 1) - checking if password contains at least one upper and one lower character
bool containsLowAndUpperCharacter(char word[]){
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
        return true;
    }   
    else{
        return false;
    }
}

// Second condition (LVL 2) - this function is true if entered word contains characters at least PARAM groupes
bool havingRightCharset(char word[], int param){
    int low = 0, up = 0, num = 0, spec = 0;
    bool foundLow = false, foundUp = false, foundNum = false, foundSpec = false;
    for(int i = 0;i<(sizeof(word)/sizeof(word[0]))+COUNT_OF_ASCII;i++){
        if(word[i] == '\0'){
            break;
        }
        if(word[i] >= 'a' && word[i] <='z'){
            low = 1;
            
        }
        if(word[i] >= 'A' && word[i] <='Z'){    // When entered word which contains number or lower, upper or special character, then relevant counter is set to 1  
            up = 1;
            
        }
        if(word[i] >= '0' && word[i] <='9'){
            num = 1;
            
        }
        if((word[i] >= 32 && word[i] <= 47) || (word[i] >= 58 && word[i] <= 64) || (word[i] >= 91 && word[i] <= 96) || (word[i] >= 123 && word[i] <= 126)){
            spec = 1;
            
        }
        if(param == 1 && low + up + num + spec >= 1){
            return true;
        }
        if(param == 2 && low + up + num + spec >= 2){ // when low + up + num + spec > 2, word contains character from 3 or 4 groups
            return true;
        }
        if(param == 3 && low + up + num + spec >= 3){
            return true;
        }
        if(param == 4 && low + up + num + spec >= 4){
            return true;
        }   
    }
    
    
    return false;
    
} 

// Third condition (LVL 3) - this function returns true if word doesn't contain PARAM characters next to each other
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



int minimal(char pw[], int previousLength){
    int currentLength = 0;
    for(int i = 1;pw[i]!='\0';i++){  //length or every password
        currentLength++;
    }
    if(currentLength<previousLength){
        return currentLength;           
    }
    else{
        return previousLength;
    }

    
}



// Fourth condition (LVL 4) checking if password doesn't contain same substrings with the lenght of PARAM 
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

    if(LEVEL < 1 || LEVEL > 4){
        printf("Byla zadana nespravna hodnota u argumentu LEVEL\n");
        return 0;
    }

    if(PARAM < 1 || PARAM > 4){
        printf("Byla zadana nespravna hodnota u argumentu PARAM\n");
        return 0;
    }

    while(fgets(pw, 101, stdin) != NULL){
        wordCount++;
        min = minimal(pw, min);
        
        if(LEVEL == 1 && containsLowAndUpperCharacter(pw)){
            printf("\n%s", pw);
        }
        if(LEVEL == 2 && containsLowAndUpperCharacter(pw) && havingRightCharset(pw, PARAM)){
            printf("\n%s", pw);
        }
        if(LEVEL == 3 && containsLowAndUpperCharacter(pw) && havingRightCharset(pw, PARAM) && notContainsSameChars(pw, PARAM)){
            printf("\n%s", pw);
        }
        if(LEVEL == 4 && containsLowAndUpperCharacter(pw) && havingRightCharset(pw, PARAM) && notContainsSameChars(pw, PARAM) && notContainsSameStrings(pw, PARAM)){
            printf("\n%s", pw);
        }
        
        
        int i = 0;
        while(pw[i] != '\0'){
            allCount++;
            i++;
        }
        
        //counting NCHARS
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
