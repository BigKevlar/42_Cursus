
function redirectIfNotLoggedIn()
{
    const username = localStorage.getItem("username");
    const token = localStorage.getItem("token");
    const isLoggedIn = !!username && !!token;
    if (!isLoggedIn) {
        window.location.href = "/login";
    }
    return isLoggedIn;
}

export default redirectIfNotLoggedIn;