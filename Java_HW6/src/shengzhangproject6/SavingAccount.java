/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package shengzhangproject6;

/**
 *
 * @author shengzhang0830
 */

// SavingAccount inherits BankAccount
public class SavingAccount extends BankAccount
{
    private double interestRate = 0.05;

    
    public SavingAccount(String first, String last, String social, double initial)
    {
        super(first, last, social, initial);
    }
    
    public void deposit(double deposit)
    {
        balance = balance + deposit;
        System.out.println(super.customer.getName() + " deposited $" + deposit + ". Current balance $" + balance);
    }
     
    public void withdraw(double withdrewal)
    {
        if(withdrewal > balance)
        {
            System.out.println("Unable to withdraw $" + withdrewal + " for " + super.customer.getName() + " due to insufficient funds");
        }
        else
        {    
            balance = balance - withdrewal;
            System.out.println(super.customer.getName() + " withdrew $" + withdrewal + ". su balance $" + balance);
        }
    }
     
     
    public void applyInterest()
    {
        balance = balance * (1 + interestRate);
    }
    
    public void checkBalance()
    {
        System.out.println(super.customer.getName() + ", Balance $" + balance);
    }
        
    
    public double getBalance()
    {
        return balance;
    }
    
    public void print()
    {
        System.out.print(super.customer.getName() + ", accn #: ");
        printIntArray(accountNumber);
        System.out.println(", Balance $" + balance);
        
    }

}
