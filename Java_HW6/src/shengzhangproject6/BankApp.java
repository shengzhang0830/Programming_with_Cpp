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
public class BankApp {
    public static void main(String[] args)
    {

      // Construct a BankDatabase object
      BankDatabase acctDatabase = new BankDatabase();

      // Use the member functions defined in the BankDatabase class
      acctDatabase.createCheckingAccount("Alin Parker", "123-45-6789", 20000.0f);

      acctDatabase.createSavingAccount("Mary Jones", "987-65-4321", 15000.0f);

      acctDatabase.createSavingAccount("John Smith", "123-45-6789", 12000.0f);

      acctDatabase.print();

      acctDatabase.applyInterest();

      acctDatabase.print();
    }
}
