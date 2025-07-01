function getRandomNumberInRange(min, max) {
    let rand = Math.floor(Math.random() * (max - min + 1)) + min;

    while (rand === 0)
        rand = Math.floor(Math.random() * (max - min + 1)) + min;
    return rand;
}

module.exports = { getRandomNumberInRange };