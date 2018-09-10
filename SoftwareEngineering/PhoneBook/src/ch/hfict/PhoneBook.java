package ch.hfict;

import java.util.HashMap;
import java.util.Map;

/**
 * Manage phone numbers of Persons
 * 
 * @author stud
 *
 */
public class PhoneBook {

  public static void main(String[] args) {
    Map<Person, String> phoneBook = 
        new HashMap<Person, String>();

    Person walter = new Person("Walter", "White");
    phoneBook.put(walter, "070 123 4576");
    
    Person key = new Person("Walter", "White");
    System.out.println(key.getFirstname() +": " +
        phoneBook.get(key));
  }
  
}
