package com.company;


import java.util.Scanner;

public class TrieImplementation {

    private Trie root;

    public TrieImplementation() {
        root = new Trie();
        root.setEndOfTheWord(false);
    }

    private void createTrie(String inputLine) {
        for (String word : inputLine.split(" ")) {
            Trie temp = root;
            for (int index = 0; index < word.length(); index++) {

                Character character = word.charAt(index);

                temp.getTrieHashMap().put(character, new Trie());

                temp = temp.getTrieHashMap().get(character);
            }

            temp.getTrieHashMap().get(word.charAt(word.length() - 1)).setEndOfTheWord(true);
        }

    }

    private boolean findWhetherGivenStringExistOrNot(String wordToFind) {
        for (int index = 0; index < wordToFind.length() - 1; index++) {
            Character character = wordToFind.charAt(index);
            if (root.getTrieHashMap().containsKey(character) && !root.getTrieHashMap().get(character).isEndOfTheWord()) {
                root = root.getTrieHashMap().get(wordToFind.charAt(index));
            } else
                return false;
        }
        if (root.getTrieHashMap().containsKey(wordToFind.charAt(wordToFind.length() - 1)) && root.getTrieHashMap().get(wordToFind.charAt(wordToFind.length() - 1)).isEndOfTheWord())
            return true;
        return false;
    }

    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);

        String inputString = scanner.nextLine();
        String wordToFind = scanner.next();

        TrieImplementation trieImplementation = new TrieImplementation();
        trieImplementation.createTrie(inputString);
        System.out.print(trieImplementation.findWhetherGivenStringExistOrNot(wordToFind));
    }
}
