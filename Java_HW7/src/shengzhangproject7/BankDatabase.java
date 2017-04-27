/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package shengzhangproject7;

import java.util.*;


/**
 *
 * @author shengzhang0830
 */
public class BankDatabase 
{
    // BankDatabase is an arraylist of BankAccount 
    private ArrayList<BankAccount> database = new ArrayList<BankAccount>();
    
    // Default constructor
    public BankDatabase()
    {
        
    }

    // Create a checking account in the database
    void createCheckingAccount(String customerName, String ssn, float deposit)
    {
        CheckingAccount checking = new CheckingAccount(customerName.split(" ")[0],customerName.split(" ")[1], ssn, deposit);
        database.add(checking);
    }
    
    // Create a saving account in the database
    void createSavingAccount(String customerName, String ssn, float deposit)
    {
         SavingAccount saving = new SavingAccount(customerName.split(" ")[0],customerName.split(" ")[1], ssn, deposit);
         database.add(saving);
    }
    
    // Print out the bank accounts in the database after sorting according to the balance
    void print()
    {
        // Define the comparator to be used in the sort function later
        Comparator<BankAccount> comparator = new Comparator<BankAccount>()
        {
            public int compare (BankAccount b1, BankAccount b2)
            {
                if (b1.getBalance()>b2.getBalance())
                    return 1;
                else if (b1.getBalance()<b2.getBalance())
                    return -1;
                else
                    return 0;
            }
        };

        // Sort
        Collections.sort(database,comparator);
        
        // Print
        for(int i = 0; i < database.size(); i++)
        {
            database.get(i).print();
        }
        
    }
    
    // Apply interest
    void applyInterest()
    {
        for (int i = 0; i <database.size(); i++)
        {
            database.get(i).applyInterest();
        }
    }

}
