/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package shengzhangproject5;

/**
 *
 * @author shengzhang0830
 */
public class BankMain 
{

    public static void main(String[] args) {       

        // Create two checking accounts and one saving account
        CheckingAccount acct1 = new CheckingAccount("Alin", "Parker", "123-45-6789", 1000.0);
        CheckingAccount acct2 = new CheckingAccount("Mary", "Jones", "987-65-4321", 500.0);
        SavingAccount acct3 = new SavingAccount("John", "Smith", "1233-45-6789", 200.0);

        // Deposit
        acct1.deposit(22000.00);
        acct2.deposit(12000.00);

        // Withdraw
        acct1.withdraw(2000.00);
        acct2.withdraw(1000.00);       

        // Apply interest
        acct1.applyInterest();
        acct2.applyInterest();

        // Check balance
        acct1.checkBalance();
        acct2.checkBalance();
        
        // Withdraw
        acct1.withdraw(30000.00);

    }

}
