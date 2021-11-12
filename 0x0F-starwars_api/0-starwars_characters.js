#!/usr/bin/node

// must use request module
const request = require('request');

// parsing input
const movieId = process.argv[2];

// define api url
const url = `https://swapi.dev/api/films/${movieId}/`;

try {
  // send request
  request(url, async function (err, response, body) {
    if (err) {
      console.log(err);
    } else {
      // parse the body for the list of characters
      const characters = JSON.parse(body).characters;
      for (const char of characters) {
        // await for the Promise to be fullfilled and returns value
        const res = await new Promise((resolve, reject) => {
          // send in new request to grab character name
          request(char, (err, res, html) => {
            if (err) {
              reject(err);
            } else {
              resolve(JSON.parse(html).name);
            }
          });
        });
        // print Promise value
        console.log(res);
      }
    }
  });
} catch (catchError) {
  console.log(catchError);
}
