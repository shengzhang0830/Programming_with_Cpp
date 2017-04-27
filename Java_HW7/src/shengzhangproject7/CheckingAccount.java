/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package shengzhangproject7;

/**
 *
 * @author shengzhang0830
 */

// CheckingAccount inherits BankAccount
public class CheckingAccount extends BankAccount
{
    private double interestRate = 0.02;

    
    public CheckingAccount(String first, String last, String social, double initial)
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
            System.out.println(super.customer.getName() + " withdrew $" + withdrewal + ". Current balance $" + balance);
        }
    }
     
     
     
    public void applyInterest()
    {
        if(balance > 10000)
        {
            balance = balance + interestRate * (balance - 10000);
        }
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
