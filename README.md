# Inverted Index

## Idea
Searching through text documents is a process that requires lots of computational powers. For a
given search keyword, the naive searching algorithm would be to pass through the corpus of
documents iteratively and for each document, check whether the word exists in the document. This
algorithm will be very slow for a large corpus of documents. If the corpus had D documents each
having W words each of length L then the complexity of the naive approach would be O(D*W*L)
(The complexity of naive search in each document is O(W*L) ).
In this project, you are required to optimize this searching algorithm. The straightforward way is to
build an index. For an index, you will need to store all the words that occurred in a document. An
inverted index works in the reverse way. Instead of storing the words that occurred in each
document, you will store the ids of the documents in which each word has occurred.

<table>
  <tr>
    <th>id</td>
    <th>Document</td>
    <th>Forward index {word: count}</td>
    <th>Inverted index {word: document id}</td>
  </tr>
  <tr>
    <td>1</td>
    <td>foo</td>
    <td>foo: 1</td>
    <td rowspan="3">foo: 1 <br> bar: 2, 3  <br>var: 3</td>
  </tr>
  <tr>
    <td>2</td>
    <td>bar</td>
    <td>bar: 1</td>
  </tr>
  <tr>
    <td>3</td>
    <td>bar var</td>
    <td>bar: 1, var:1</td>
  </tr>
</table>

In the table shown above, there are three documents of ids 1,2 and 3. To build a forward index,
you would need to create a data structure that stores the frequency of each word in the document.
To find if a word occurred in the document, you would basically check the frequency of the word in
this data structure. But, this won’t hugely improve the performance.
To build an inverted index, you will need to:
1. Find the set of all unique words in the document.
2. For each word, store the ids of the documents in which they occurred in a data structure.
To find the documents that contain a certain word, you would just query the inverted index and find
the documents’ ids. You can use a BST (Binary Search Tree) to build the inverted index such that
the key is the word you are searching for and the value of each node is a container to store the
documents’ ids (the container may be a linear data structure such as an array, linked list, stack,
queue, ...)

## Main requirements
The program should have a GUI (Graphical User Interface) that has the following features:
* Specifying a certain directory (folder) containing the set of files. Each file has a unique
name and represents a document.
* Loading all the files in the specified directory and building the inverted index.
* Searching for all the files containing a certain word Wi and visually showing the number of
documents having this word and showing these documents clearly to the user.
