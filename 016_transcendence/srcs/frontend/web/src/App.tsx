import { BrowserRouter as Router, Routes, Route, useLocation } from "react-router-dom";
import { useEffect } from "react";
import Home from "./pages/Home";
import Login from "./pages/Login";
import Signup from "./pages/Signup";
import Menu from "./pages/Menu";
import Game from "./pages/Game";
import Status from "./pages/Status";
import Header from "./components/layout/Header";
import OAuthSuccess from './components/utils/OAuthSuccess';
import Particles from './components/utils/Particles';
import Doom from "./pages/Doom";
import Team from "./pages/Team";
import Sprinter from "./pages/Sprinter";
import NotFound from "./pages/NotFound";
import Tournament from "./pages/Tournament";

function ScrollToTop() {
  const { pathname } = useLocation();
  
  useEffect(() => {
    window.scrollTo(0, 0);
  }, [pathname]);
  
  return null;
}

function App() {
  return (
    <Router>
      <div className="relative flex flex-col min-h-screen bg-gray-900 text-white overflow-hidden">
        <ScrollToTop />
        <Particles />
        <div className="relative z-10 flex flex-col min-h-screen">
          <Header />
          <main className="flex-grow">
            <Routes>
              <Route path="/" element={<Home />} />
              <Route path="/login" element={<Login />} />
              <Route path="/signup" element={<Signup />} />
              <Route path="/menu" element={<Menu />} />
              <Route path="/doom" element={<Doom />} />
              <Route path="/game" element={<Game />} />
              <Route path="/status" element={<Status />} />
              <Route path="/auth/success" element={<OAuthSuccess />} />
              <Route path="/team" element={<Team />} />
              <Route path="/sprinter" element={<Sprinter />} />
              <Route path="*" element={<NotFound />} />
              <Route path="/tournament" element={<Tournament />} />
            </Routes>
          </main>
        </div>
      </div>
    </Router>
  );
}

export default App;
