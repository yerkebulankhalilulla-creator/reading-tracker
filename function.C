
#include <stdio.h>
#include <time.h>

#define MAX_BOOKS 100

struct book
{
    char title[100];
    char author[100];
    int pages;
};

void ShowM(void);
void AddBook(struct book books[], int *count);
void GetM(struct book books[], int *count);
void ShowB(struct book books[], int *count);

void ShowM(void)
{
    printf("\n===== READING TRACKER =====\n");
    printf("1. Add a book\n");
    printf("2. Show all books\n");
    printf("3. Start reading\n");
    printf("4. Show statistics\n");
    printf("0. Exit\n");
    printf("Choose an option: ");
}

void AddBook(struct book books[], int *count)
{
    if (*count >= MAX_BOOKS)
    {
        printf("Library is full!\n");
        return;
    }

    printf("Enter book title: ");
    if (scanf(" %99[^\n]", books[*count].title) != 1)
    {
        printf("Invalid title!\n");
        return;
    }

    printf("Enter author: ");
    if (scanf(" %99[^\n]", books[*count].author) != 1)
    {
        printf("Invalid author!\n");
        return;
    }

    printf("Enter number of pages: ");
    if (scanf("%d", &books[*count].pages) != 1 ||
        books[*count].pages <= 0)
    {
        int ch;
        while ((ch = getchar()) != '\n' && ch != EOF)
        {
        }

        printf("Invalid number of pages!\n");
        return;
    }

    (*count)++;

    printf("Book added successfully!\n");
}

void ShowB(struct book books[], int *count)
{
    if ( *count == 0 )
    {
        printf("No added book yet.\n");
    }

    else{

        for ( int i = 0; i < *count; ++i)
        {
            printf("%d) %s - by %s\n", i + 1, books[i].title, books[i].author);
        }         
    }
}


void StartR(struct book books[], int *count)
{
    int choice;

    if ( *count == 0 )
    {
        printf("First add a book.\n");
    }

    else
    {
        ShowB(books, *count);

        printf( "To start reading just choose a number of book.\n" );
    
        if(scanf("%d", &choice) != 1 || choice > *count || choice < *count)
        {
            printf("Incorrect input\n");
        }

        else 
        {
               time_t current_time;
               current_time = time(NULL);
        }



    }



}




void Timer()





void GetM(struct book books[], int *count)
{
    int choice;

    while (1)
    {  
        ShowM(); //

        int result = scanf("%d", &choice);

        if (result == EOF)
        {
            printf("\nGoodbye!\n");
            return;
        }

        if (result != 1)
        {
            int ch;
            while ((ch = getchar()) != '\n' && ch != EOF)
            {
            }

            printf("Invalid input. Enter a number.\n");
            continue;
        }

        switch (choice)
        {
            case 1:
                AddBook(books, count);
                break;

            case 2:
                ShowB(books, count);
                break;

            case 3:
                printf("Start reading - coming soon!\n");
                break;

            case 4:
                printf("Statistics - coming soon!\n");
                break;

            case 0:
                printf("Goodbye! Thank you for using the program.\n");
                return;

            default:
                printf("Unknown menu option. Please try again.\n");
                break;
        }
    }
}

int main(void)
{
    struct book books[MAX_BOOKS];
    int count = 0;

    GetM(books, &count);

    return 0;
}
