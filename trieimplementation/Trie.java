package com.company;


import java.util.HashMap;

public class Trie {

    private boolean isEndOfTheWord;
    private HashMap<Character,Trie> trieHashMap;

    public Trie(){
        this.isEndOfTheWord = false;
        trieHashMap = new HashMap<>();
    }

    public void setEndOfTheWord(boolean endOfTheWord) {
        isEndOfTheWord = endOfTheWord;
    }

    public HashMap<Character, Trie> getTrieHashMap() {
        return trieHashMap;
    }

    public boolean isEndOfTheWord() {
        return isEndOfTheWord;
    }
}
