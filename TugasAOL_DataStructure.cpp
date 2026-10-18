#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 1000

struct node* root = NULL;
int number = 1;
int counter = 0;

typedef struct node{
    struct node* child[SIZE];
    char *description;
    bool isword;
}node;

struct finder{
    char words[1001];
    bool id;
}find[1001];

node* newnode(){
    node* nd = (node*)malloc(sizeof(node));

    for(int i = 0; i < SIZE; i++){
        nd->child[i] = NULL;
    }

    nd->isword = false;
    nd->description = NULL;
    return nd;
}

bool string_has_space(char string[]){

    for(int i = 0; i < strlen(string); i++){
        if(string[i] == ' '){
            return true;
        }
    }

    return false;
}

bool description_has_space(char string[]){
    int space_counter = 0;

     for(int i = 0; i < strlen(string); i++){
        if(string[i] == ' '){
            space_counter++;
        }
    }

    if(space_counter < 2){
        return false;
    } else {
        return true;
    }
}

void insertnode(node** root, char* word, char deskripsi[]){

    if(*root == NULL){
        *root = newnode();
    }
    node* curr = *root;

    int len = strlen(word);

    for (int i = 0 ; i < len; i++){

        if(curr->child[word[i]] == NULL){
            curr->child[word[i]] = newnode();
        }

        curr = curr->child[word[i]];
    }

    if(curr->isword){
        curr->description = strdup(deskripsi);
        printf("Succesfully updated a slang word.\n");
    } else {
        curr->description = strdup(deskripsi); //strdup digunakan untuk membuat duplikat dari suatu string dalam alokasi memori yang dinamic
        printf("Succesfully released a new slang word.\n");
        curr->isword = true;
        strcpy(find[counter].words, word);
        counter++;
    }

    return;
}

void search(node* root, char* text){
    int length = strlen(text);
    node* curr = root;

    if(curr == NULL){
        printf("There is no word in the dictionary\n");
        return;
    }

    for(int i = 0; i < length; i++){
        if(curr->child[text[i]] == NULL){
            printf("There is no word \"%s\" in the dictionary.\n", text);
            return;
        }

        curr = curr->child[text[i]];
    }

    printf("Slang word  : %s\n", text);
    printf("Description : %s\n", curr->description);
    
}

void printtrie_rec(node* nd, char *prefix, int length){

    char newprefix[length+2];
    memcpy(newprefix, prefix, length);
    newprefix[length+1] = '\0';

    if(nd->isword){
        printf("%d. %s\n", number, prefix);
        number++;
    }

    for(int i = 0; i < SIZE; i++){
        if(nd->child[i] != NULL){
            newprefix[length] = i;
            printtrie_rec(nd->child[i], newprefix, length+1);
        }
    }

}

void printtrie(node* root){

    if(root == NULL){
        printf("There is no slang word yet in the dictionary.\n");
        return;
    } 

    printf("List of all slang words in the dictionary:\n");
    printtrie_rec(root, NULL, 0);
}

int main(){

    int loop = 1;

    while (loop == 1){

        int options;
        char newword[1001];
        char deskripsi[1001];
        char findword[1001];
        char wordprefix[1001];
        int finder = 0;

        printf("1. Release a new slang word\n");
        printf("2. Search a slang word\n");
        printf("3. View all slang words starting with a certain prefix word\n");
        printf("4. View all slang words\n");
        printf("5. Exit\n\n");

        printf("Pick an option -> ");

        scanf("%d", &options);
        getchar();


        switch(options){

            case 1:

            {
                printf("Input a new slang word [Must be more than 1 characters and contains no space]: ");
                scanf("%[^\n]", newword);
                getchar();

                bool string_space = string_has_space(newword);

                while(strlen(newword) <= 1 || string_space == true){
                    printf("Input a new slang word [Must be more than 1 characters and contains no space]: ");
                    scanf("%[^\n]", newword);
                    getchar();

                    string_space = string_has_space(newword);
                }

                printf("Input a new slang word description [Must be more than 2 words]: ");
                scanf("%[^\n]", deskripsi);
                getchar();

                bool description_space = description_has_space(deskripsi);

                while(description_space == false){
                    printf("Input a new slang word description [Must be more than 2 words]: ");
                    scanf("%[^\n]", deskripsi);
                    getchar();

                    description_space = description_has_space(deskripsi);
                }

                insertnode(&root, newword, deskripsi);
                printf("\n");
                break;

            }

            case 2:

            {
                printf("Input a slang word to be searched [Must be more than 1 characters and contains no space]: ");
                scanf("%[^\n]", findword);
                getchar();

                bool space = string_has_space(findword);

                while(strlen(findword) <= 1 || space == true){
                    printf("Input a slang word to be searched [Must be more than 1 characters and contains no space]: ");
                    scanf("%[^\n]", findword);
                    getchar();

                    space = string_has_space(findword);
                }

                search(root, findword);
                printf("\n");
                break;

            }

            case 3:
                number = 1;
                printf("Input a prefix to be searched: ");
                scanf("%s", wordprefix);
                getchar();

                for(int i = 0; i < counter; i++){
                    find[i].id = true;
                }

               for(int i = 0; i < counter; i++){
                    for(int j = 0; j < strlen(wordprefix); j++){
                        if(find[i].words[j] != wordprefix[j]){
                            find[i].id = false;
                    }
               }

               }

               for(int i = 0; i < counter; i++){
                if(find[i].id == true){
                    printf("%d. %s\n", number, find[i].words);
                    number++;
                    finder = 1;
                }
               }

               if(finder == 0){
                printf("There is no prefix \"%s\" in the dictionary.\n", wordprefix);
               }

               printf("\n");
                break;

            case 4:
                number = 1;
                printtrie(root);
                printf("\n");
                break;

            case 5:
                system("cls");
                printf("Thank you... Have a nice day :)\n");
                loop = 0;
                break;

            default:
                printf("Please enter a valid option\n\n");
                break;
        }

    }

    return 0;
}