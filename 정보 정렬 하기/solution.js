var solution = function (rows) {
    var sort1 = [];
    var sort2 = [];
    var sort3 = [];

    sort1 = getUniqueNumbers(rows.sort((a, b) => a[0] - b[0]));
    sort2 = getUniqueNumbers(
        rows.sort((a, b) => {
            if (a[1] == b[1]) return 0;
            if (a[1] > b[1]) return 1;
            return -1;
        })
    );
    sort3 = getUniqueNumbers(rows.sort((a, b) => b[2] - a[2]));

    return [sort1, sort2, sort3];
};

var getUniqueNumbers = (arr) => {
    var ret = [];
    arr.forEach((x) => {
        ret.push(x[0]);
    });
    return ret;
};