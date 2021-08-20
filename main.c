#include <stdio.h>
#include <string.h>
int selection()
{
    int a;
    printf("\n\n\t\tBaler Transports\n");
    printf("\t--------------------------------\n");
    printf("\t1. Show Available Seats\n");
    printf("\t2. Book a Seat\n");
    printf("\t3. Update Information\n");
    printf("\t4. View Booking\n");
    printf("\t5. Cancel Booking\n");
    printf("\t0. Exit\n");
    printf("\tEnter an option: ");
    scanf("%d", &a);

    return a;
}

void seats()
{
    int seats[100] = {0};
    for (int i = 0; i < 50; i++)
    {
        printf("%d ", seats[i]);
    }
}

void details(int line)
{
    FILE *booking = fopen("booking-record.txt", "r");
    int count = 0;
    char lineValue[200];
    while (fgets(lineValue, 200, booking) != NULL)
    {
        if (count == line)
        {
            for (int i = 0; i < 200; i++)
            {
                if (lineValue[i] == '#')
                {
                    break;
                }
                else if (lineValue[i] == '+')
                {
                    printf("\n");
                    i++;
                }
                printf("%c", lineValue[i]);
            }
            break;
        }
        else
        {
            count++;
        }
    }
    fclose(booking);
}
int view()
{
    FILE *booking = fopen("booking-record.txt", "r");
    char sName[10], str[100], *pos;
    printf("Enter Name: ");
    scanf("%s", &sName);
    int line = -1;
    while ((fgets(str, sizeof str, booking)) != NULL)
    {
        line += 1;
        pos = strstr(str, sName);
        if (pos != NULL)
        {
            break;
        }
    }
    fclose(booking);
    details(line);
    return line;
}

void newBooking()
{
    FILE *booking = fopen("booking-record.txt", "a+");
    char name[100], phone[50], from[50], to[50];
    name[0] = ' ';
    printf("Name: ");
    scanf(" %[^\n]s", name);
    printf("Phone: ");
    scanf(" %[^\n]s", phone);
    printf("Your Current Location: ");
    scanf(" %[^\n]s", from);
    printf("Destination: ");
    scanf(" %[^\n]s", to);
    fprintf(booking, "\n");
    fprintf(booking, "%s+%s+%s+%s#", name, phone, from, to);
    fclose(booking);
}

void delete (int line)
{
    FILE *booking = fopen("booking-record.txt", "a+");
    FILE *temp = fopen("temp.txt", "a+");
    char buffer[200];
    int count = 1;
    while (fgets(buffer, sizeof buffer, booking) != NULL)
    {
        if (line + 1 != count)
        {
            fputs(buffer, temp);
        }
        count++;
    }
    fclose(booking);
    fclose(temp);
    remove("booking-record.txt");
    rename("temp.txt", "booking-record.txt");
}

void main()
{
    int line;
    int sel = selection();

    switch (sel)
    {
    case 1:
        seats();
        break;
    case 2:
        newBooking();
        break;
    case 3:
        printf("\nEnter information to search.\n");
        line = view();
        delete (line);
        printf("\n\nInsert New Informations.\n");
        newBooking();
        printf("\nTicket successfully updated.");
        break;
    case 4:
        view();
        break;
    case 5:
        line = view();
        delete (line);
        printf("\nTicket successfully cancelled.");
        break;
    default:
        printf("\tERROR: Not a valid option");
        break;
    }
}
