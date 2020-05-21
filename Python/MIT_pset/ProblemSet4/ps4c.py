# Problem Set 4C
# Name: Jonathan Daw
# Collaborators:
# Time Spent: x:xx

import string
from ps4a import get_permutations

### HELPER CODE ###
def load_words(file_name):
    """
    file_name (string): the name of the file containing
    the list of words to load

    Returns: a list of valid words. Words are strings of lowercase letters.

    Depending on the size of the word list, this function may
    take a while to finish.
    """
    
    print("Loading word list from file...")
    # inFile: file
    inFile = open(file_name, 'r')
    # wordlist: list of strings
    wordlist = []
    for line in inFile:
        wordlist.extend([word.lower() for word in line.split(' ')])
    print("  ", len(wordlist), "words loaded.")
    return wordlist

def is_word(word_list, word):
    """
    Determines if word is a valid word, ignoring
    capitalization and punctuation

    word_list (list): list of words in the dictionary.
    word (string): a possible word.

    Returns: True if word is in word_list, False otherwise

    Example:
    >>> is_word(word_list, 'bat') returns
    True
    >>> is_word(word_list, 'asdf') returns
    False
    """
    word = word.lower()
    word = word.strip(" !@#$%^&*()-_+={}[]|\:;'<>?,./\"")
    return word in word_list


### END HELPER CODE ###

WORDLIST_FILENAME = 'words.txt'

# you may find these constants helpful
VOWELS_LOWER = 'aeiou'
VOWELS_UPPER = 'AEIOU'
CONSONANTS_LOWER = 'bcdfghjklmnpqrstvwxyz'
CONSONANTS_UPPER = 'BCDFGHJKLMNPQRSTVWXYZ'

class SubMessage(object):
    def __init__(self, text):
        """
        Initializes a SubMessage object

        text (string): the message's text

        A SubMessage object has two attributes:
            self.message_text (string, determined by input text)
            self.valid_words (list, determined using helper function load_words)
        """
        self.message_text = text
        self.valid_words = load_words(WORDLIST_FILENAME)
    
    def get_message_text(self):
        """
        Used to safely access self.message_text outside of the class

        Returns: self.message_text
        """
        return self.message_text

    def get_valid_words(self):
        """
        Used to safely access a copy of self.valid_words outside of the class.
        This helps you avoid accidentally mutating class attributes.

        Returns: a COPY of self.valid_words
        """
        return self.valid_words.copy()
                
    def build_transpose_dict(self, vowels_permutation):
        """
        vowels_permutation (string): a string containing a permutation of vowels (a, e, i, o, u)

        Creates a dictionary that can be used to apply a cipher to a letter.
        The dictionary maps every uppercase and lowercase letter to an
        uppercase and lowercase letter, respectively. Vowels are shuffled
        according to vowels_permutation. The first letter in vowels_permutation
        corresponds to a, the second to e, and so on in the order a, e, i, o, u.
        The consonants remain the same. The dictionary should have 52
        keys of all the uppercase letters and all the lowercase letters.

        Example: When input "eaiuo":
        Mapping is a->e, e->a, i->i, o->u, u->o
        and "Hello World!" maps to "Hallu Wurld!"

        Returns: a dictionary mapping a letter (string) to
                 another letter (string).
        """
        
        alphabet = string.ascii_lowercase
        transpose_dict = {}
        upper_count, lower_count = 0, 0
        for case in (alphabet, alphabet.upper()):
            for letter in case:
                if letter in VOWELS_LOWER:
                    transpose_dict[letter] = vowels_permutation[lower_count]
                    lower_count += 1
                elif letter in VOWELS_UPPER:
                    transpose_dict[letter] = vowels_permutation.upper()[upper_count]
                    upper_count += 1
                else:
                    transpose_dict[letter] = letter
        return transpose_dict


    
    def apply_transpose(self, transpose_dict):
        """
        transpose_dict (dict): a transpose dictionary

        Returns: an encrypted version of the message text, based
        on the dictionary
        """
        
        decrypted_message = ""
        for char in self.message_text:
            if char in transpose_dict:
                decrypted_message += transpose_dict[char]
            else:
                decrypted_message += char
        return decrypted_message

        
class EncryptedSubMessage(SubMessage):
    def __init__(self, text):
        """
        Initializes an EncryptedSubMessage object

        text (string): the encrypted message text

        An EncryptedSubMessage object inherits from SubMessage and has two attributes:
            self.message_text (string, determined by input text)
            self.valid_words (list, determined using helper function load_words)
        """
        SubMessage.__init__(self, text)


    def decrypt_message(self):
        """
        Attempt to decrypt the encrypted message

        Idea is to go through each permutation of the vowels and test it
        on the encrypted message. For each permutation, check how many
        words in the decrypted text are valid English words, and return
        the decrypted message with the most English words.

        If no good permutations are found (i.e. no permutations result in
        at least 1 valid word), return the original string. If there are
        multiple permutations that yield the maximum number of words, return any
        one of them.

        Returns: the best decrypted message

        Hint: use your function from Part 4A
        """
        vowel_permutations = get_permutations(VOWELS_LOWER)
        most_correct_words = 0
        best_perm = ""
        # Iterates through every permutation of "aeiou"
        for current_permutation in vowel_permutations:
            correct_words = 0
            transpose_dict = self.build_transpose_dict(current_permutation)
            word_list = self.apply_transpose(transpose_dict).split()
            for word in word_list:
                if is_word(self.get_valid_words(), word):
                    correct_words += 1
            if correct_words > most_correct_words:
                most_correct_words = correct_words
                best_perm = current_permutation
        best_dict = self.build_transpose_dict(best_perm)
        decrypted_message = self.apply_transpose(best_dict)
        if most_correct_words == 0:
            return self.get_message_text()
        return decrypted_message

if __name__ == '__main__':

    # Example test case
    message = SubMessage("Hello World!")
    permutation = "eaiuo"
    enc_dict = message.build_transpose_dict(permutation)
    print("Original message:", message.get_message_text(), "Permutation:", permutation)
    print("Expected encryption:", "Hallu Wurld!")
    print("Actual encryption:", message.apply_transpose(enc_dict))
    enc_message = EncryptedSubMessage(message.apply_transpose(enc_dict))
    print("Decrypted message:", enc_message.decrypt_message())
     
    #TODO: WRITE YOUR TEST CASES HERE
    second_message = SubMessage("Today is May 21st, 2020. This is problem 4C apart of MIT 6.0001")
    permutation_2 = "oeuia"
    second_enc_dict = second_message.build_transpose_dict(permutation_2)
    print("Original message:", second_message.get_message_text(), "Permutation:",permutation_2)
    print("Expected encryption:", "Tidoy us Moy 21st, 2020. Thus us priblem 4C oport if MUT 6.0001")
    print("Actual encryption:", second_message.apply_transpose(second_enc_dict))
    second_enc_message = EncryptedSubMessage(second_message.apply_transpose(second_enc_dict))
    # Returned message may differ from the original message
    print("Decrypted message:", second_enc_message.decrypt_message())
