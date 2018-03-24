#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>

//struktura sk³adaj¹ca siê z pytania, trzech odpowiedzi i litery prawid³owej odpowiedzi
struct QuestionAnswer
{
	char question[256];
	char answerA[256];
	char answerB[256];
	char answerC[256];
	char correctAnswer[1];
};

//printfowanie gotowej struktury, traktujmy jak metodê sprawdzaj¹c¹ egzemplarz obiektu
void printfQA(struct QuestionAnswer *qA)
{
	struct QuestionAnswer lqA = *qA;
	printf("%s \n %s \n %s \n %s \n  %c \n", lqA.question, lqA.answerA, lqA.answerB, lqA.answerC, lqA.correctAnswer[0]);
}

//zapis gotowej struktury questionAnswer w pliku file
void saveQAInFile(FILE *file, struct QuestionAnswer *pqA)
{
	struct QuestionAnswer qA = *pqA;
	
	fprintf(file, qA.question);
	fprintf(file, " ");
	fprintf(file, qA.answerA);
	fprintf(file, " ");
	fprintf(file, qA.answerB);
	fprintf(file, " ");
	fprintf(file, qA.answerC);
	fprintf(file, " ");
	fprintf(file, qA.correctAnswer);
	fprintf(file, " ");
	fprintf(file, "\n");
}

//tworzenie nowej struktury questionAnswer #januszeObiektowoœci
struct QuestionAnswer newQuestionAnswer()
{
	struct QuestionAnswer qA;
	
	scanfingQuestionAnswer:
	printf("Add question, three answers, and letter of the correct one.\n Use '_' instead of spaces. \n");
	
	scanf("%s", qA.question);
	scanf("%s", qA.answerA);
	scanf("%s", qA.answerB);
	scanf("%s", qA.answerC);
	scanf("%s", qA.correctAnswer);
	//qA.correctAnswer = getch();
	//fgets(&qA.question);
	printfQA(&qA);
	
	char answer2[3];
	printf("Is input valid(yes/no)?\n");
	scanf("%s", answer2);
	if(!strcmp(answer2, "no")) goto scanfingQuestionAnswer;
	
	
	return qA; 
}

//wczytuje QuestionAnswer z pliku file, zapisuje go w miejscu pamiêci dostarczonym w argumencie
int readQuestionAnswer(FILE *file, struct QuestionAnswer *qa)
{	
	//fseek(file,0,0);
	struct QuestionAnswer lqa = *qa;

	fscanf(file, "%s %s %s %s %s", lqa.question, lqa.answerA, lqa.answerB, lqa.answerC, lqa.correctAnswer);


	//printfQA(&lqa);
	
	*qa=lqa;
	
	return 0;
}


//powiedzmy, metoda main dodawania nowych pytañ
void addingQuestion()
{
	FILE *file;
	file = fopen("testy.txt", "a");
	
	struct QuestionAnswer qA;
			
	qA = newQuestionAnswer();
	saveQAInFile(file, &qA);

	fclose(file);
}

void askQuestion(struct QuestionAnswer *pqA)
{
	struct QuestionAnswer qA = *pqA;
	char answer;
	
	printf("%s\n", qA.question);
	printf("a) %s \nb) %s \nc) %s\n", qA.answerA, qA.answerB, qA.answerC);
	
	answer = getch();
	
	//if(!strcmp((char[])answer, qA.correctAnswer)) printf("suka blyac. good!");
	if(answer == qA.correctAnswer[0]) printf("suka blyac. good!\n");
	else printf("wrooooong\n");
}

//metoda main rozwi¹zywania testu
void takingTest()
{
	printf("Started Test\n");
	FILE *file;
	file = fopen("testy.txt", "r");
	
	//pogrzebany pies
	struct QuestionAnswer qa;
	struct QuestionAnswer *pqa = &qa;
	
	do
	{
		//qa = readQuestionAnswer(file, pqa);
		readQuestionAnswer(file, pqa);
		sleep(1);
		askQuestion(&qa);
		
		printf("Another question? (YES(y)/NO(any key))\n");
		if(getch()!='y') break;
	}while(1);
	
	
}

//mainik
int main()
{
//	FILE *file;
//	*file = fopen("testy.txt", 'a+');
	char answer[10];
	
	while(1){
		choosingMainMode:
		printf("choose mode: (adding questions(A)/taking test(T))/quit(Q)\n");
		sleep(1);
		scanf("%s", answer);
	
		if(!strcmp(answer, "Q")) exit(0);
		if(!strcmp(answer,"A") && !strcmp(answer,"T")) goto choosingMainMode;
	
		if(!strcmp(answer,"A")) addingQuestion();
		else takingTest();
		
	}
	return 0;
}
