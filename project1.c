#include "project1.h"

//function declarations
void push(struct MP3* first, struct MP3* last);
void deleteMP3(struct MP3*, char* name);
void printListForward(struct MP3*);
void printListBackward(struct MP3*);
struct MP3* createMP3();

int main(){	
	
	//establish a char varibale for fgets() and first and last pointers for future reference
	char* str[55];
	struct MP3* first = createMP3();
	struct MP3* last = createMP3();
	
	//while loop will restart the program after each operation in case the user wishes to complete another operation
	while (1){

		 printf("Enter the number that corresponds to the operation you wish to complete: '\n'1 to add a song '\n'2 to remove a song '\n'3 to print the list from beginning to end '\n'4 to print the list from end to beginning. '\n'");
		//establish a command code and select the corresponding operation
		int* commandCode = malloc(sizeof(int));
		scanf("%d", commandCode);   
		switch (*commandCode){

			case 1: push(first, last); 
				break;

			case 2: printf("Enter the name of the artist who's song you want to be deleted:");
				char* dT = fgets(*str, 55, stdin);  
				deleteMP3(first, dT);
				break;

			case 3: printListForward(first);
				break;
	
			case 4: printListBackward(last);
				break;
		}
	}	

}

//function to add a song to the end of the list
void  push(struct MP3* first, struct MP3* last){
	
	char str[55];
	//allocating memory for new MP3 node
	struct MP3* newSong = createMP3();
	
	while((getchar()) != '\n');
	//setting the song TItle
	printf("Enter the song Title");
	fgets(str, 55, stdin);
	newSong->songTitle = str;

	//setting the artist name
	printf("Enter the artist Name");
	fgets(str, 55, stdin);
	newSong->artistName = str;

	//setting the realease year
	printf("Enter the year the song was released");
	int* year;
	scanf ("%d", year);
	newSong->year = *year;

	//setting the run Time
	printf("Enter the song's runTime");
	int* rT;
	scanf("%d", rT);
	newSong->runTime = *rT;

	//adding the MP3 to the linked list
	if (first == NULL){
		first = newSong;
		last = newSong;
		newSong->prev = NULL;
		newSong->next = NULL;
	}else {
		last->next = newSong;
		newSong->prev = last;
		newSong->next = NULL;
		newSong = last;
	}
}

//deletes all songs from the list with a specific artist name
void deleteMP3(struct MP3* first, char* name){
	struct MP3* tmp = first;
	while (tmp->next != NULL){
		if (tmp->artistName = name){
			struct MP3* delete = tmp;
			tmp = tmp->next; 
			delete->prev->next = delete->next;
			delete->next->prev = delete->prev;
			free(delete);
		}else {
			tmp = tmp->next;
		}
	}
}
	

//recieves the first pointer and iterates through printing all the information for each MP3
void printListForward(struct MP3* first)
{
	struct MP3* tmp = first;
	while(tmp->next != NULL){
		printf("Song Title: %s", tmp->songTitle);
		printf("Artist Name: %s ", tmp->artistName);
		printf("Year: %d ", tmp->year);
		printf("Run Time: %d ", tmp->runTime); 
		tmp = tmp->next; 
	}
	printf("Song Title: %s", tmp->songTitle);
	printf("Artist Name: %s ", tmp->artistName);
	printf("Year: %d ", tmp->year);
	printf("Run Time: %d ", tmp->runTime);
}

//recieves the last pointer as reference and iterates through printing all information for each MP3
void printListBackward(struct MP3* last){
	struct MP3* tmp = last;
	while (tmp->next != NULL){
		printf("Song Title: %s", tmp->songTitle);
		printf("Artist Name: %s ", tmp->artistName);
		printf("Year: %d ", tmp->year);
		printf("Run Time: %d ", tmp->runTime);
		tmp = tmp->next;
	}
	printf("Song Title: %s", tmp->songTitle);
	printf("Artist Name: %s ", tmp->artistName);
	printf("Year: %d ", tmp->year);
	printf("Run Time: %d ", tmp->runTime);
}

//constructor for MP3
struct MP3* createMP3(){
	struct MP3* tmp = malloc(sizeof(struct MP3));
	tmp->next = NULL;
	tmp->prev = NULL;
	return tmp;
}
