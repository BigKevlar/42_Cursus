import React, { useEffect, useRef, useState } from 'react';

interface PingPongGameProps { className?: string; }

const PingPongGame: React.FC<PingPongGameProps> = ({ className = '' }) => {

  const canvasRef = useRef<HTMLCanvasElement>(null);
  const requestIdRef = useRef<number>(0);
  const [initialized, setInitialized] = useState(false);
  
  const state = useRef({
    ball: {
      x: 0,
      y: 0,
      radius: 6,
      velocityX: 5,
      velocityY: 3,
      speed: 5,
      color: "#ffffff",
      isResetting: false
    },
    leftPaddle: {
      x: 0,
      y: 0,
      width: 12,
      height: 90,
      color: "#6366f1",
      score: 0,
      speed: 2.5,
      direction: 1
    },
    rightPaddle: {
      x: 0,
      y: 0,
      width: 12,
      height: 90,
      color: "#6366f1",
      score: 0,
      speed: 2.5,
      direction: 1
    },
    net: {
      x: 0,
      y: 0,
      width: 2,
      height: 10,
      color: "rgba(255, 255, 255, 0.2)"
    },
    court: {
      color: "#1f2937"
    },
    scaleFactor: 1
  });

  // INITIALIZE
  useEffect(() => {
    const canvas = canvasRef.current;
    if (!canvas) return;

    const ctx = canvas.getContext('2d');
    if (!ctx) return;

    const resizeCanvas = () => {
      const displayWidth = canvas.offsetWidth;
      const displayHeight = canvas.offsetHeight;
      
      // Calculate scale factor
      const referenceWidth = 400;
      const newScaleFactor = Math.max(0.2, Math.min(1, canvas.width / referenceWidth));
      state.current.scaleFactor = newScaleFactor;
      
      // Set render dimensions
      canvas.width = displayWidth;
      canvas.height = displayHeight;
      
      // Set display dimensions
      canvas.style.width = `${displayWidth}px`;
      canvas.style.height = `${displayHeight}px`;
      
      // Scale game elements
      const ballRadius = Math.max(2, Math.floor(5 * newScaleFactor));
      state.current.ball.radius = ballRadius;

      const paddleWidth = Math.max(2, Math.floor(8 * newScaleFactor));
      const paddleHeight = Math.max(15, Math.floor(90 * newScaleFactor));
      
      state.current.leftPaddle.width = paddleWidth;
      state.current.leftPaddle.height = paddleHeight;
      state.current.rightPaddle.width = paddleWidth;
      state.current.rightPaddle.height = paddleHeight;

      // Adjust net dimensions
      state.current.net.width = Math.max(1, Math.floor(2 * newScaleFactor));

      // Calculate paddle offset
      const paddleOffset = Math.max(15, Math.floor(30 * newScaleFactor));

      // Ball position
      state.current.ball.x = canvas.width / 2;
      state.current.ball.y = canvas.height / 2;

      // Paddles position
      state.current.leftPaddle.x = paddleOffset;
      state.current.leftPaddle.y = canvas.height / 2 - state.current.leftPaddle.height / 2;
      state.current.rightPaddle.x = canvas.width - paddleOffset - state.current.rightPaddle.width;
      state.current.rightPaddle.y = canvas.height / 2 - state.current.rightPaddle.height / 2;
      
      // Net position
      state.current.net.x = canvas.width / 2 - state.current.net.width / 2;
           
      setInitialized(true);
    }

    resizeCanvas();
    const handleResize = () => { resizeCanvas(); }
    window.addEventListener('resize', handleResize);

    return () => {
      window.removeEventListener('resize', handleResize);
      cancelAnimationFrame(requestIdRef.current);
    }
  }, []);

  // -------------------------- DRAWING FUNCTIONS -------------------------- //

  const drawRect = (ctx: CanvasRenderingContext2D, x: number, y: number, w: number, h: number, color: string) => {
    ctx.fillStyle = color;
    ctx.fillRect(x, y, w, h);
  }
  
  const drawCircle = (ctx: CanvasRenderingContext2D, x: number, y: number, r: number, color: string) => {
    ctx.fillStyle = color;
    ctx.beginPath();
    ctx.arc(x, y, r, 0, Math.PI * 2, false);
    ctx.closePath();
    ctx.fill();
  }
  
  const drawRoundedRect = (ctx: CanvasRenderingContext2D, x: number, y: number, width: number, height: number, radius: number, color: string) => {
    ctx.fillStyle = color;
    ctx.beginPath();
    ctx.moveTo(x + radius, y);
    ctx.arcTo(x + width, y, x + width, y + height, radius);
    ctx.arcTo(x + width, y + height, x, y + height, radius);
    ctx.arcTo(x, y + height, x, y, radius);
    ctx.arcTo(x, y, x + width, y, radius);
    ctx.closePath();
    ctx.fill();
  }
  
  const drawCourtBorder = (ctx: CanvasRenderingContext2D, canvas: HTMLCanvasElement, borderWidth: number = 3) => {
    const scaledBorderWidth = Math.max(1, Math.floor(borderWidth * state.current.scaleFactor));
    const EDGE_PADDING = Math.max(10, Math.floor(20 * state.current.scaleFactor));
    
    ctx.strokeStyle = "rgba(255, 255, 255, 0.15)";
    ctx.lineWidth = scaledBorderWidth;
    ctx.lineJoin = "round";
    const borderGradient = ctx.createLinearGradient(0, 0, 0, canvas.height);
    borderGradient.addColorStop(0, "rgba(99, 102, 241, 0.4)");
    borderGradient.addColorStop(0.5, "rgba(255, 255, 255, 0.15)");
    borderGradient.addColorStop(1, "rgba(99, 102, 241, 0.4)");
    ctx.strokeStyle = borderGradient;
    
    ctx.strokeRect(scaledBorderWidth + EDGE_PADDING/2, scaledBorderWidth + EDGE_PADDING/2, canvas.width - (scaledBorderWidth*2 + EDGE_PADDING), canvas.height - (scaledBorderWidth*2 + EDGE_PADDING));
  }
  
  const drawNet = (ctx: CanvasRenderingContext2D, canvas: HTMLCanvasElement) => {
    const EDGE_PADDING = Math.max(10, Math.floor(20 * state.current.scaleFactor));
    const centerX = canvas.width / 2;
    const playableHeight = canvas.height - (EDGE_PADDING * 2);
    const startY = 15;
    const endY = canvas.height - 15;
    const midY = startY + (playableHeight / 2); 
    const circleRadius = Math.max(5, Math.floor(10 * state.current.scaleFactor));
    const lineWidth = Math.max(1, Math.floor(2 * state.current.scaleFactor));

    ctx.beginPath();
    ctx.strokeStyle = "rgba(255, 255, 255, 0.2)";
    ctx.lineWidth = lineWidth;

    // Vertical line
    ctx.moveTo(centerX, startY);
    ctx.lineTo(centerX, startY);
    ctx.lineTo(centerX, endY);
    ctx.stroke();
    
    // Circle at the center
    ctx.beginPath();
    ctx.strokeStyle = "rgba(255, 255, 255, 0.2)";
    ctx.lineWidth = lineWidth;
    ctx.arc(centerX, midY - 1, circleRadius, 0, Math.PI * 2);
    ctx.stroke();
    
    // Dot in the center
    ctx.beginPath();
    ctx.fillStyle = "rgba(255, 255, 255, 0.2)";
    ctx.arc(centerX, midY - 1, Math.max(1, 1.5 * state.current.scaleFactor), 0, Math.PI * 2);
    ctx.fill();
  }

  // -------------------------- DRAWING FUNCTIONS -------------------------- //

  // AI MOVEMENT
  const updateAI = (canvas: HTMLCanvasElement) => {
    const { leftPaddle, rightPaddle, ball, scaleFactor } = state.current;
    const EDGE_PADDING = Math.max(10, Math.floor(20 * scaleFactor));
    
    if (ball.isResetting) return;    
    
    // Track the ball
    let leftTarget = ball.y - leftPaddle.height / 2;
    let rightTarget = ball.y - rightPaddle.height / 2;
    
    // Extended deadzone for stability when ball is moving straight
    const DEADZONE = Math.max(2, Math.floor(4 * scaleFactor));

    // Check if ball is moving mostly horizontally (to avoid jittery paddle movements)
    const isMovingMostlyHorizontal = Math.abs(ball.velocityX) > Math.abs(ball.velocityY) * 3;
    
    // Increase deadzone when ball is moving horizontally to prevent small jitters
    const effectiveDeadzone = isMovingMostlyHorizontal ? DEADZONE * 2 : DEADZONE;
    
    // Only calculate if ball is moving toward the left paddle
    if (ball.velocityX < 0 && ball.x < canvas.width * 0.7) {
      const timeToReach = (ball.x - leftPaddle.x - leftPaddle.width) / -ball.velocityX;
      if (timeToReach > 0 && timeToReach < 60) {
        const predictedY = ball.y + ball.velocityY * timeToReach;
        
        if (Math.random() < 0.2 && timeToReach < 30) {
          leftTarget = predictedY - leftPaddle.height / 2;
          if (rightPaddle.y > canvas.height / 2)  leftTarget -= leftPaddle.height * 0.3;
          else                                    leftTarget += leftPaddle.height * 0.3;
        } else {
          if (isMovingMostlyHorizontal)           leftTarget = 0.7 * (predictedY - leftPaddle.height / 2) + 0.3 * leftPaddle.y;
          else                                    leftTarget = predictedY - leftPaddle.height / 2;
        }
      }
    }
    
    // Only calculate if ball is moving toward the right paddle
    if (ball.velocityX > 0 && ball.x > canvas.width * 0.3) {
      const timeToReach = (rightPaddle.x - ball.x - ball.radius) / ball.velocityX;
      if (timeToReach > 0 && timeToReach < 60) {
        const predictedY = ball.y + ball.velocityY * timeToReach;
        
        if (Math.random() < 0.2 && timeToReach < 30) {
          rightTarget = predictedY - rightPaddle.height / 2;
          if (leftPaddle.y > canvas.height / 2)   rightTarget -= rightPaddle.height * 0.3;
          else                                    rightTarget += rightPaddle.height * 0.3;
        } else {
          if (isMovingMostlyHorizontal)           rightTarget = 0.7 * (predictedY - rightPaddle.height / 2) + 0.3 * rightPaddle.y;
          else                                    rightTarget = predictedY - rightPaddle.height / 2;
        }
      }
    }
    
	  // Don't move if the target is too close
    if (Math.abs(leftTarget - leftPaddle.y) < effectiveDeadzone)    leftTarget = leftPaddle.y;
    if (Math.abs(rightTarget - rightPaddle.y) < effectiveDeadzone)  rightTarget = rightPaddle.y;
    
    // Apply edge padding
    leftTarget = Math.max(EDGE_PADDING, Math.min(leftTarget, canvas.height - leftPaddle.height - EDGE_PADDING));
    rightTarget = Math.max(EDGE_PADDING, Math.min(rightTarget, canvas.height - rightPaddle.height - EDGE_PADDING));
    
    // Simplified movement calculation with fixed lerp factors for better performance
    let leftDelta = (leftTarget - leftPaddle.y) * 0.06;
    let rightDelta = (rightTarget - rightPaddle.y) * 0.06;
    
    // Apply maximum speed limit
    const MAX_SPEED = Math.max(5, Math.floor(10 * scaleFactor)); 
    leftDelta = Math.max(Math.min(leftDelta, MAX_SPEED), -MAX_SPEED);
    rightDelta = Math.max(Math.min(rightDelta, MAX_SPEED), -MAX_SPEED);
    
    // Apply movement
    leftPaddle.y += leftDelta;
    rightPaddle.y += rightDelta;
    
    // Boundary check
    if (leftPaddle.y < EDGE_PADDING) leftPaddle.y = EDGE_PADDING;
    if (leftPaddle.y > canvas.height - leftPaddle.height - EDGE_PADDING) leftPaddle.y = canvas.height - leftPaddle.height - EDGE_PADDING;
    
    if (rightPaddle.y < EDGE_PADDING) rightPaddle.y = EDGE_PADDING;
    if (rightPaddle.y > canvas.height - rightPaddle.height - EDGE_PADDING) rightPaddle.y = canvas.height - rightPaddle.height - EDGE_PADDING;
  }
  
  // COLLISION
  const collision = (ball: any, paddle: any) => {
    const ballTop = ball.y - ball.radius;
    const ballBottom = ball.y + ball.radius;
    const ballLeft = ball.x - ball.radius;
    const ballRight = ball.x + ball.radius;

    const paddleTop = paddle.y;
    const paddleBottom = paddle.y + paddle.height;
    const paddleLeft = paddle.x;
    const paddleRight = paddle.x + paddle.width;

    return (ballRight > paddleLeft && ballLeft < paddleRight && ballBottom > paddleTop && ballTop < paddleBottom);
  }

  // UPDATE
  const update = (canvas: HTMLCanvasElement) => {
    const { ball, leftPaddle, rightPaddle, scaleFactor } = state.current;

    if (!ball.isResetting) {
      // Update paddles
      updateAI(canvas);

      // Move the ball
      ball.x += ball.velocityX;
      ball.y += ball.velocityY;
      
      // Improved collision (top and bottom)
      const WALL_PADDING = Math.max(6, Math.floor((12 + ball.radius * 1.2) * scaleFactor));
      if (ball.y - ball.radius < WALL_PADDING) {
        ball.y = WALL_PADDING + ball.radius;
        ball.velocityY = Math.abs(ball.velocityY);
        if (Math.abs(ball.velocityY) < 2) ball.velocityY = 2 * Math.sign(ball.velocityY);
      } else if (ball.y + ball.radius > canvas.height - WALL_PADDING) {
        ball.y = canvas.height - WALL_PADDING - ball.radius;
        ball.velocityY = -Math.abs(ball.velocityY);        
        if (Math.abs(ball.velocityY) < 2) ball.velocityY = 2 * Math.sign(ball.velocityY);
      }
      
      let player = ball.x < canvas.width / 2 ? leftPaddle : rightPaddle;
      
      // If the ball hits a paddle
      if (collision(ball, player)) {       
        const ballCenterY = ball.y;
        const paddleTop = player.y;
        const paddleBottom = player.y + player.height;
        const paddleLeft = player.x;
        const paddleRight = player.x + player.width;
        const paddleCenterY = player.y + player.height / 2;
        
        if ((ball.x >= player.x && ball.x <= (player.x + player.width)) && (((Math.abs(ball.y - player.y) <= ball.radius) && (ball.velocityY > 0)) || ((Math.abs(ball.y - (player.y + player.height)) <= ball.radius) && (ball.velocityY < 0)))) {
          // If is a collision with the top or bottom of the paddle (invert only the Y velocity)
          ball.velocityY = -ball.velocityY;         
          if (Math.abs(ball.velocityY) < 2) ball.velocityY = 2 * Math.sign(ball.velocityY);
          if (ballCenterY < paddleCenterY) ball.y = paddleTop - ball.radius - 1;
          else ball.y = paddleBottom + ball.radius + 1;
        } else {
          // Normal collision (calculate where the ball hit the paddle)
          let collidePoint = (ballCenterY - paddleCenterY) / (player.height / 2);
          let angleRad = (Math.PI / 4) * collidePoint;

          // 30% of the time, attempt strategic shots (fake but whatever)
          if (Math.random() < 0.3) {
            if (collidePoint > 0) angleRad = Math.PI / 3.5;
            else                  angleRad = -Math.PI / 3.5;
          }
          
          // Ball direction based on which paddle hit it
          const direction = player === leftPaddle ? 1 : -1;
          
          // Change speed based on where it hit
          ball.velocityX = direction * ball.speed * Math.cos(angleRad);
          ball.velocityY = ball.speed * Math.sin(angleRad);
          
          if (Math.abs(ball.velocityX) < 2) ball.velocityX = 2 * Math.sign(ball.velocityX);         
          if (player === leftPaddle)        ball.x = paddleRight + ball.radius + 1;
          else                              ball.x = paddleLeft - ball.radius - 1;
        }
        
        // Increase speed with a maximum limit
        if (ball.speed < Math.max(10, Math.floor(20 * scaleFactor))) ball.speed += 0.2;
      }
      
      // Reset ball if it scores (Not gonna showing it really)
      if (ball.x - ball.radius < 0 || ball.x + ball.radius > canvas.width) {
        if (ball.x - ball.radius < 0) rightPaddle.score++;
        else                          leftPaddle.score++;
        
        const direction = ball.velocityX > 0 ? -1 : 1;
        ball.isResetting = true;        
        ball.velocityX = 0;
        ball.velocityY = 0;
        ball.x = ball.x < 0 ? -20 : canvas.width + 20;
        
        // Reset ball after a delay
        setTimeout(() => {
          if (canvasRef.current) {
            // Position ball in center
            ball.x = canvas.width / 2;
            ball.y = canvas.height / 2;
            ball.speed = 5;

            // Wait a bit longer before starting movement again
            setTimeout(() => {
              if (canvasRef.current) {
                ball.velocityX = direction * 5;
                ball.velocityY = (Math.random() - 0.5) * 4;
                if (Math.abs(ball.velocityY) < 2) ball.velocityY = 2 * Math.sign(ball.velocityY) || 2;
                ball.isResetting = false;
              }
            }, 50);
          }
        }, 300);
      }
    }
  }

  // RENDER
  const render = (ctx: CanvasRenderingContext2D, canvas: HTMLCanvasElement) => {
    const { scaleFactor } = state.current;
    
    // Clear
    drawRect(ctx, 0, 0, canvas.width, canvas.height, state.current.court.color);
    
    // Draw border
    drawCourtBorder(ctx, canvas);

    // Draw net
    drawNet(ctx, canvas);
    
    // Draw left paddle
    drawRoundedRect(ctx, state.current.leftPaddle.x, state.current.leftPaddle.y, state.current.leftPaddle.width, state.current.leftPaddle.height, Math.max(2, Math.floor(5 * scaleFactor)), state.current.leftPaddle.color);
    
    // Draw right paddle
    drawRoundedRect(ctx, state.current.rightPaddle.x, state.current.rightPaddle.y, state.current.rightPaddle.width, state.current.rightPaddle.height, Math.max(2, Math.floor(5 * scaleFactor)), state.current.rightPaddle.color);
    
    // Draw ball
    drawCircle(ctx, state.current.ball.x, state.current.ball.y, state.current.ball.radius, state.current.ball.color);
  }
  
	// LOOP
	useEffect(() => {
	  if (!initialized) return;
	  
	  const animate = () => {
		  const canvas = canvasRef.current;
		  if (!canvas) return;
		
		  const ctx = canvas.getContext('2d');
		  if (!ctx) return;
		
		  // Update game
		  update(canvas);
		
		  // Render game
		  render(ctx, canvas);
		
		  requestIdRef.current = requestAnimationFrame(animate);
	  }
	  
	  requestIdRef.current = requestAnimationFrame(animate);	  
	  return () => { cancelAnimationFrame(requestIdRef.current); }
	}, [initialized]);
  
	return (
	  <div className={`relative w-full h-full ${className}`}>
		<canvas 
		  ref={canvasRef} 
		  className="w-full h-full rounded-xl shadow-inner bg-gray-800"
		/>
	  </div>
	);

}

export default PingPongGame;
