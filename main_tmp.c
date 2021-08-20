#include <stdio.h>
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
void main()
{
    int sel = selection();

    switch (sel)
    {
    case 2:
        newBooking();
        break;
    case 4:
        view();
        break;
    default:
        printf("\tERROR: Not a valid option");
        break;
    }
}