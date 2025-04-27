const express = require("express")
const users = require("./MOCK_DATA.json")
const app = express();

const PORT = 8000;

app.listen(PORT, ()=>{
    console.log(`Server is running at PORT: ${PORT}`)
});

//get users
app.get("/api/users",(req , res)=>{
    console.log("done");
    return res.json(users);
})

app.get("/api/users/:id",(req,res)=>{
    const userId = Number(req.params.id);
    const user = users.find(u => u.id === userId);
    if(user === null || typeof user === "undefined"){
        res.json({ message: "No data found" });
    }
    return res.json(user);
})