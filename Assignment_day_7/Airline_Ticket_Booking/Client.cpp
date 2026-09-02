
#include"BusinessTicket.h"
#include"FirstClassTicket.h"
#include"EconomyTicket.h"
#include"FlightTicket.h"
int main() {

	int N;
	cout << "Enter number of passenger bookings to process: ";
	cin >> N;

	FlightTicket** Flight = new FlightTicket*[N];
	for (int i = 0;i < N;i++) {
		string Pname;
		string Fnumber;
		double bFare;
		int BagCount;
		int TotalWeight;
		int Category;
		cout << "\n====Enter The Details Of Passenger " << i + 1 << "====\n" << endl;
		cout << "\nEnter the name of passenger :-  ";
		cin >> Pname;
		cout << "\nEnter the Flight number :-  " ;
		cin >> Fnumber;
		cout << "\nEnter Base Fare :- ";
		cin >> bFare;
		cout << "\n Enter the Bag count :- ";
		cin >> BagCount;
		cout << "\n Enter Total Weight :- ";
		cin >> TotalWeight;
		cout << "\nSelect Category\n1.Economy , 2.Business , 3.FirstClass :- ";
		cin >> Category;
		switch (Category) {
			case 1:
				double extraBagFeePerKg;
				double seatSelectionFee;
				cout << "\nEnter the extraBagFeesPerKg :- ";
				cin >> extraBagFeePerKg;
				cout << "\nEnter the SeatSelection Fees :- ";
				cin >> seatSelectionFee;
				Flight[i] = new EconomyTicket(extraBagFeePerKg, seatSelectionFee, Pname, Fnumber , bFare, BagCount, TotalWeight);
				break;

			case 2:
				double loungeAccessFee;
				double priorityBoardingFee;
				cout << "\nEnter the Lounge Access Fees :- ";
				cin >> loungeAccessFee;
				cout << "\nEnter the Bording Fees :- ";
				cin >> priorityBoardingFee;
				Flight[i] = new BusinessTicket(loungeAccessFee, priorityBoardingFee, Pname, Fnumber, bFare, BagCount, TotalWeight);
				break;

			case 3:
				double conciergeServiceFee;
				cout << "\nEnter the Concierge Service Fee :- ";
				cin >> conciergeServiceFee;
				Flight[i] = new FirstClassTicket(conciergeServiceFee, Pname, Fnumber, bFare, BagCount, TotalWeight);

				break;
			defalut:
				cout << "Invalid Input";

		}

	}
	for (int i = 0;i < N;i++) {
		Flight[i]->printBoardingPass();
	}

	return 0;
}