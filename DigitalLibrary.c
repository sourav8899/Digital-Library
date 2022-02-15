#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include <ctype.h>

typedef struct
{
    long long int ISBN;
    char Name[13];
    int numberOfAuthors;
    char author[10][10];
    char publisher[13];
    int year;
}BOOK;
BOOK insertBook(BOOK b);
int booksInAGivernYear(BOOK b[],int year1, int year2, int numberOfBooks);
void bookByAGivenAuthor(BOOK b[], char*authorName, int numberOfBooks);
char* bookByAGivenPublisher(BOOK b[], char*publisherName);
void* sortByISBN(BOOK b[]);
void* sortByName(BOOK b[]);
void* sortByFirstAuthor(BOOK b[]);



int main()
{
    int ch,year1,year2;
    int i = 0,j,n = 0, k = 0;
    char Author[10];
    BOOK b[100];
    while(1)
    {
        printf("\033[1;34m");
        printf("\n--------------------WELCOME TO DIGITAL LIBRARY--------------------\n");
        printf("\033[0m");
        printf("Enter your choice:\n");

        printf("1.Insert\n2.Books In Between Two Given Years\n3.Find The Books By The Author Name\n");
        scanf("%d",&ch);

    switch(ch)
    {

        case 1:
        printf("No Of Books:");
        do
        {
            scanf("%d",&n);
        }
        while(n <= 0);
        n = n + i;
        while(i  < n )
        {
            printf("\n----BOOK%d-------\n",i + 1);
            b[i] = insertBook(b[i]);
            i++;
        }
        break;
        case 2:printf("Enter The Years:\n");
        do
        {
            printf("Year 1:");
            scanf("%d",&year1);
            printf("Year 2:");
            scanf("%d",&year2);
        }
        while(year1 < 0 && year2 < 0);
        int a = booksInAGivernYear(b,year1,year2, n);
        printf("\033[1;33m");
        printf(": ) Found %d books between the year %d and %d!!",a,year1,year2);
        printf("\033[0m");
        break;
        case 3:if(n == 0)
        {
            printf("\033[0;31m");
            printf(": ( There is no book in the library!!");
            printf("\033[0m");
            break;
        }
        printf("Author's Name:");
        scanf("\n%[^\n]s",Author);
        printf("Books By Author:");
        bookByAGivenAuthor(b, Author,n);
        break;
    }
    }
}
BOOK insertBook(BOOK b)
{   int k = 0;
    int j;

        printf("Book:");
        scanf(" %[^\n]s",b.Name);
        printf("Number of author's:");
        scanf("%d",&j);
        b.numberOfAuthors = j;
        printf("Name Of Author/Authors:");
        while( k < j )
        {
            scanf("\n%[^\n]%*c", b.author[k]);
            k++;
        }
        printf("ISBN NO:");
        scanf("%lld",&b.ISBN);
        printf("Year:");
        scanf("%d",&b.year);
        printf("Publisher:");
        scanf("\n%[^\n]s",b.publisher);
        printf("\033[1;33m");
        printf(": ) %s Book Inserted Sucessfully!!!",b.Name);
        printf("\033[0m");
        return b;

}
int booksInAGivernYear(BOOK b[],int year1, int year2, int numberOfBooks)
{
    int counter = 0;
    for(int i = 0; i < numberOfBooks; i++)
    {
        if(year1 <= b[i].year && year2 >= b[i].year)
        {
            counter++;
            printf("\033[1;32m");
            printf("%d.%s\n",counter,b[i].Name);
            printf("\033[0m");
        }
    }
    return counter;
}
void bookByAGivenAuthor(BOOK b[], char authorName[], int numberOfBooks)
{

    int counter = 0;
    int j = 0;
    bool FoundBook= false;
    for(int i = 0; i < numberOfBooks; i++)
    {

        for(j = 0; j < b[i].numberOfAuthors; j++ )
        {
          if(strcmp(authorName, b[i].author[j]) == 0)
          {
              FoundBook = true;
              counter++;
              printf("\033[1;33m");
              printf("%d. %s\n",counter,b[i].Name);
              printf("\033[0m");
          }

        }
    }
    if(FoundBook == false)
    {
        printf("\033[0;31m");
        printf(": ( Sorry Don't Found Any Book By the Author");
        printf("\033[0m");
    }

}



