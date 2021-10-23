#include <stdio.h>

# define LEVEL 4
# define PARAM 3

int containsLowAndUpperCharacter(char pw[]){
    for(int i=0;i!='\0';i++){
        
    }
    return 1; 
}

int main(){
        
    const char passwords[] = "heslo\ndelsiheslo\nhesloscislemtreba123\nhesloscislem5aspecialnimznakem;";
    char pw[100];
    int pointer = 0;

    for(int counter = 0; counter< sizeof passwords/ sizeof passwords[0]; counter++){
        if (passwords[counter]!='\n' || passwords[counter]!='\0'){
            pw[pointer] += passwords[counter];
            pointer+=1;
        }

        else{
            printf("%s", pw);
            pointer = 0;
        }
        
    }
    
    
    
    return 0;
}
