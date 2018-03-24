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
	
	if(answer == qA.correctAnswer[0]) printf("cyka blyac. good!\n");
	else printf("wrooooong\n");
}

//metoda main rozwi¹zywania testu
void takingTest()
{
	printf("Started Test\n");
	FILE *file;
	file = fopen("testy.txt", "r");
	
	
	struct QuestionAnswer qa;
	struct QuestionAnswer *pqa = &qa;
	
	do
	{	
		readQuestionAnswer(file, pqa);
		askQuestion(&qa);
		
		printf("Another question? (YES(y)/NO(any key))\n");
		if(getch()!='y') break;
	}while(1);
	
	
}

//printf about
void printfAbout()
{
	printf("Author: Bartlomiej Kirejczyk\n");
	printf("Github: Kiririridev\n");
	printf("Program is #1 assignment for Jay Raszka's classes.\n");
	printf("Enjoy!\n");
}

//mainik
int main()
{

	char answer;
	
	while(1){
		printf("choose mode: (adding questions(a)/taking test(t))/info(i)/quit(q)\n");
		answer = getch();		
		
		if(answer =='q') exit(0);
		if(answer == 'a') addingQuestion();
		else if(answer == 't')takingTest();
		else if(answer=='i') printfAbout();
	}
	return 0;
}
