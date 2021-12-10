#!/usr/bin/python3
""" Count it! """
import requests


def count_words(subreddit, word_list, after="", word_count={}):
    '''queries the Reddit API, and prints a sorted count of given keywords'''

    # on first call initialize word counts to 0
    if not word_count:
        for word in word_list:
            word_count[word] = 0
    # if next page is not returned into after (we reached the last page)
    if after is None:
        # create our word matrix with the word, and each count being an element
        word_list = [[key, value] for key, value in word_count.items()]
        word_list = sorted(word_list, key=lambda x: (-x[1], x[0]))

        # print word, and word count
        for word in word_list:
            if word[1]:
                print("{}: {}".format(word[0].lower(), word[1]))
        return None

    # define request parameters
    url = "https://www.reddit.com/r/{}/hot/.json".format(subreddit)
    headers = {'user-agent': 'my-app/0.0.1'}
    params = {'limit': 100, 'after': after}
    request = requests.get(url,
                           headers=headers,
                           params=params,
                           allow_redirects=False)

    if request.status_code != 200:
        return None
    try:
        # get next page
        after = request.json().get("data").get("after")

        # returns the subreddit
        children = request.json().get("data").get("children")

        for child in children:
            # get title of each child (each post)
            title = child.get("data").get("title")
            lower = [t.lower() for t in title.split(' ')]
            # update our word list with what we found
            for word in word_list:
                word_count[word] += lower.count(word.lower())
    except Exception:
        return None
    count_words(subreddit, word_list, after, word_count)
