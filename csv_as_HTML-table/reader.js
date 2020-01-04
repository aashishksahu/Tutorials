function read_csv(file) {
    // create a FileReader object
    var reader = new FileReader();
    // read file as text
    reader.readAsText(file[0]);

    // onload is an event that gets triggered after 
    // the file is successfully loaded
    // after which the defined function is executed
    reader.onload = function (evt) {
        let data = evt.target.result;
        // using regex to replace escape characters with | 
        // and splitting to form array of rows 
        data = data.replace(/\n/g, "|")
        data = data.replace(/\r/g, '').split("|");

        // create a new array to contain all the rows 
        var new_data = new Array();
        // loop over all the elements of the csv data
        for (row in data) {
            // split the values in each column
            let col = data[row].split(",");
            
            // store the column values in a nested array 
            new_data[row] = new Array();
            // loop over all the values in a column
            for(c in col){
                // store each value to the nested array created above
                new_data[row][c] = col[c];
            }

            // new_data is an array that stores value of 
            // each column of each row of the csv data  
        }
        displayTable(new_data);
    }
}


function displayTable(data) {
    // create a table element
    var dataTable = document.createElement("TABLE");
    dataTable.setAttribute("id", "data")
    // add table to html body
    document.body.appendChild(dataTable);

    for (row in data) {
        let table = document.getElementById("data");
        // create a row
        let tableRow = table.insertRow(row);

        // loop over each column in the row
        for (col in data[row]) {
            // create a column in the row
            var tableCell = tableRow.insertCell(col);
            tableCell.innerHTML = data[row][col];
        }
    }
}