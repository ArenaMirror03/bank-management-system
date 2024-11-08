#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct BankAccount {
  char accountNumber[11];
  double balance;
  int isCreated;
};

void createAccount(struct BankAccount *account);
void depositMoney(struct BankAccount *account);
void withdrawMoney(struct BankAccount *account);
void checkBalance(struct BankAccount *account);

int main() {
  struct BankAccount account = {.isCreated = 0, .balance = 0.0};
  int choice;

  while (1) {
    printf("\n===== Banking Management System =====\n");
    printf("1. Create Account\n");
    printf("2. Deposit Money\n");
    printf("3. Withdraw Money\n");
    printf("4. Check Balance\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
      createAccount(&account);
      break;
    case 2:
      depositMoney(&account);
      break;
    case 3:
      withdrawMoney(&account);
      break;
    case 4:
      checkBalance(&account);
      break;
    case 5:
      printf("Exiting...\n");
      exit(0);
    default:
      printf("Invalid choice! Please try again.\n");
    }
  }

  return 0;
}

void createAccount(struct BankAccount *account) {
  if (account->isCreated) {
    printf("Account already created with account number %s.\n",
           account->accountNumber);
    return;
  }

  printf("Enter 11-digit account number: ");
  scanf("%s", account->accountNumber);

  if (strlen(account->accountNumber) != 11) {
    printf("Invalid account number! Please enter exactly 11 digits.\n");
    return;
  }

  account->isCreated = 1;
  account->balance = 0.0;
  printf("Account created successfully!\n");
}

void depositMoney(struct BankAccount *account) {
  if (!account->isCreated) {
    printf("Please create an account first.\n");
    return;
  }

  double amount;
  printf("Enter amount to deposit (greater than or equal to 500): ");
  scanf("%lf", &amount);

  if (amount < 500 || (int)amount != amount) {
    printf("Invalid amount! Please enter an amount of at least 500 in whole "
           "numbers.\n");
    return;
  }

  account->balance += amount;
  printf("Amount deposited successfully! Current balance: %.2f\n",
         account->balance);
}

void withdrawMoney(struct BankAccount *account) {
  if (!account->isCreated) {
    printf("Please create an account first.\n");
    return;
  }

  double amount;
  printf("Enter amount to withdraw: ");
  scanf("%lf", &amount);

  if (amount <= 0 || (int)amount != amount) {
    printf("Invalid amount! Please enter a valid amount in whole numbers.\n");
    return;
  }

  if (amount > account->balance) {
    printf("Insufficient balance! Current balance: %.2f\n", account->balance);
    return;
  }

  account->balance -= amount;
  printf("Amount withdrawn successfully! Remaining balance: %.2f\n",
         account->balance);
}

void checkBalance(struct BankAccount *account) {
  if (!account->isCreated) {
    printf("Please create an account first.\n");
    return;
  }

  printf("Current balance: %.2f\n", account->balance);
}
